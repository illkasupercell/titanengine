SELECT 
    `1000, 1000000 field`
    (SELECT group_concat(band_category_languages.name SEPARATOR ', ')
    FROM calendar_entry_categories
    LEFT JOIN band_category_languages ON band_category_languages.band_category_id = calendar_entry_categories.band_category_id
    WHERE calendar_entry_categories.calendar_entry_id = calendar_entries.id
    AND band_category_languages.language_id = 1
    GROUP BY calendar_entry_categories.calendar_entry_id) AS band_category_string,
    (SELECT entry.id
    FROM calendar_entries AS entry
    WHERE entry.entry_kind_parent_id = calendar_entries.id
    AND entry.profile_type_id = 10869
    AND entry.profile_type = 1) AS move_to_personal_calendar,
    (SELECT count(moved_entry.id)
    FROM calendar_entries AS moved_entry
    WHERE moved_entry.entry_kind_parent_id = calendar_entries.id
    AND moved_entry.status = 3) AS count_moved,
    (SELECT user_images.image
    FROM calendar_entries AS calendar_entries1
    LEFT JOIN user_images ON user_images.id = calendar_entries1.image
    WHERE calendar_entries1.id = calendar_entries.entry_kind_parent_id
    AND calendar_entries.entry_kind = 4) AS festival_image,
    (SELECT countries1.code
    FROM calendar_entries AS calendar_entries1
    LEFT JOIN locations AS locations1 ON locations1.id = calendar_entries1.location_id
    LEFT JOIN countries AS countries1 ON countries1.id = locations1.country_id
    WHERE calendar_entries1.id = calendar_entries.entry_kind_parent_id
    AND calendar_entries.entry_kind = 4) AS festival_country_code,
    (SELECT count(*)
    FROM calendar_entry_likes
    WHERE calendar_entry_likes.calendar_entry_id = calendar_entries.id) AS count_of_likes,
    (SELECT count(*)
    FROM calendar_entry_likes
    WHERE calendar_entry_likes.calendar_entry_id = calendar_entries.id
    AND calendar_entry_likes.user_id = 10869 ) AS is_like,
    (SELECT group_concat(entry_type_languages.name SEPARATOR ', ')
    FROM calendar_entry_types
    LEFT JOIN entry_type_languages ON entry_type_languages.entry_type_id = calendar_entry_types.entry_type_id
    WHERE (calendar_entry_types.calendar_entry_id = calendar_entries.id
    OR calendar_entry_types.calendar_entry_id = calendar_entries.entry_kind_parent_id)
    AND entry_type_languages.language_id = 1
    GROUP BY calendar_entry_types.calendar_entry_id) AS entry_types_string,
    (SELECT band_addresses.city_name
    FROM band_addresses
    WHERE band_addresses.band_id = calendar_entries.profile_type_id) AS band_city_name,
    (SELECT countries.code
    FROM band_addresses
    LEFT JOIN countries ON countries.id = band_addresses.country_id
    WHERE band_addresses.band_id = calendar_entries.profile_type_id) AS band_country_code,
    (SELECT group_concat(genre_languages.name SEPARATOR ', ')
    FROM calendar_entry_genres
    LEFT JOIN genre_languages ON genre_languages.genre_id = calendar_entry_genres.genre_id
    WHERE calendar_entry_genres.calendar_entry_id = calendar_entries.id
    AND genre_languages.language_id = 1
    GROUP BY calendar_entry_genres.calendar_entry_id) AS genre_string
FROM `calendar_entries`
LEFT JOIN `locations` ON `locations`.`id` = `calendar_entries`.`location_id`
LEFT JOIN `calendar_entries` AS `festival` ON `festival`.`id` = `calendar_entries`.`entry_kind_parent_id`
LEFT JOIN `locations` AS `festival_location` ON `festival_location`.`id` = ( 
    SELECT calendar_entries1.id
    FROM calendar_entries AS calendar_entries1
    WHERE calendar_entries1.id = calendar_entries.entry_kind_parent_id
    AND calendar_entries.entry_kind = 4
)
LEFT JOIN `countries` ON `countries`.`id` = `locations`.`country_id`
LEFT JOIN `country_languages` ON `country_languages`.`country_id` = `locations`.`country_id`
LEFT JOIN `states` ON `states`.`id` = `locations`.`state_id`
LEFT JOIN `bands` ON `bands`.`id` = `calendar_entries`.`profile_type_id`
AND `bands`.`soft_delete` = 0
AND `bands`.`status` = 1
LEFT JOIN `band_images` ON `band_images`.`id` = `calendar_entries`.`image`
LEFT JOIN `band_privacy_settings` ON `band_privacy_settings`.`band_id` = `calendar_entries`.`profile_type_id`
WHERE (`bands`.`soft_delete` = 0 OR `bands`.`soft_delete` IS NULL)
AND (`bands`.`status` = 1 OR `bands`.`status` IS NULL)
AND ((
        (SELECT count(*)
        FROM band_administrators
        WHERE band_administrators.band_id = bands.id
        AND band_administrators.user_id = 10869 ) > ? OR `band_privacy_settings`.`band_privacy_level` != ?
    ) AND (
        (SELECT user_type
        FROM users
        WHERE users.id = 10869 ) = ? OR `band_privacy_settings`.`band_privacy_level` != ?
    ) AND (
        (SELECT count(*)
        FROM user_bands
        WHERE user_bands.band_id = bands.id
        AND user_bands.status = 1
        AND user_bands.user_id = 10869 ) > ? OR `band_privacy_settings`.`band_privacy_level` != ?
    ) OR `band_privacy_settings`.`band_privacy_level` IS NULL
) AND (`festival`.`entry_kind` = ? OR `festival`.`id` IS NULL)
AND (date(`calendar_entries`.`date_from`) >= ?)
AND `calendar_entries`.`soft_delete` = ?
AND (`country_languages`.`language_id` = ? OR `country_languages`.`language_id` IS NULL)
AND `calendar_entries`.`entry_kind` IN (?, ?)
AND `calendar_entries`.`event_class` IN (?, ?)
AND `calendar_entries`.`status` = ?
GROUP BY `1000, 1000000 field`
ORDER BY calendar_entries.date_from
LIMIT 1000, 20
