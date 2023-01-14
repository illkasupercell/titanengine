function throw_artefact(obj)
	if obj==nil then
		return
	end
	math.randomseed(time_global())
	local rnd=math.random(10)
	local sect = obj:section()
	local lv = obj:level_vertex_id()
	local gv = obj:game_vertex_id()
	local pos = obj:position()
	local off_x = 2
	local off_y = 1.5
	local off_z = 2
	pos.x = pos.x + off_x
	pos.y = pos.y + off_y
	pos.z = pos.z + off_z	
	if lv and gv and pos then
		math.randomseed(time_global())
		if string.find(sect, "witches") then			
			if string.find(sect, "weak") then
				math.randomseed(time_global())
				if math.random(4) == 1 then alife():create("af_electra_sparkler", pos, lv, gv) end
			elseif string.find(sect, "average") then
				math.randomseed(time_global())
				if math.random(6) == 1 then alife():create("af_electra_sparkler", pos, lv, gv) end
				if math.random(4) == 1 then alife():create("af_electra_flash", pos, lv, gv) end
			else
				math.randomseed(time_global())
				if math.random(4) == 1 then alife():create("af_electra_moonlight", pos, lv, gv) end
				if math.random(5) == 1 then alife():create("af_electra_flash", pos, lv, gv) end
				if math.random(5) == 1 then alife():create("af_electra_sparkler", pos, lv, gv) end
			end
			
		elseif string.find(sect, "mosquito") then
			math.randomseed(time_global())
			if string.find(sect, "weak") then
				if math.random(6) == 1 then alife():create("af_cristall_flower", pos, lv, gv) end
			elseif string.find(sect, "average") then
				if math.random(4) == 1 then alife():create("af_cristall_flower", pos, lv, gv) end
				if math.random(5) == 1 then alife():create("af_medusa", pos, lv, gv) end
			else
				if math.random(6) 	== 1 then alife():create("af_night_star", pos, lv, gv) end
				if math.random(4)  == 1 then alife():create("af_medusa", pos, lv, gv) end
				if math.random(5)  == 1 then alife():create("af_cristall_flower", pos, lv, gv) end
			end
			
		elseif string.find(sect, "mincer") then
			math.randomseed(time_global())
			if string.find(sect, "weak") then
				if math.random(6)==1 then alife():create("af_blood", pos, lv, gv) end
			elseif string.find(sect, "average") then
				if math.random(5) == 1 then alife():create("af_blood", pos, lv, gv) end
				if math.random(4) <= 1 then alife():create("af_mincer_meat", pos, lv, gv) end
			else
				if math.random(6) == 1 then alife():create("af_soul", pos, lv, gv) end
				if math.random(4) == 1 then alife():create("af_mincer_meat", pos, lv, gv) end
				if math.random(5) == 1 then alife():create("af_blood", pos, lv, gv) end
			end
			
		elseif string.find(sect, "gravi") then
			math.randomseed(time_global())
			if string.find(sect, "weak") then
				if math.random(6)==1 then alife():create("af_vyvert", pos, lv, gv) end
			elseif string.find(sect, "average") then
				if math.random(4) == 1 then alife():create("af_vyvert", pos, lv, gv) end
				if math.random(5) <= 1 then alife():create("af_gravi", pos, lv, gv) end
			else
				if math.random(6) == 1 then alife():create("af_gold_fish", pos, lv, gv) end
				if math.random(4) == 1 then alife():create("af_gravi", pos, lv, gv) end
				if math.random(5) == 1 then alife():create("af_vyvert", pos, lv, gv) end
			end
			
		elseif string.find(sect, "ameba") or string.find(sect, "burning_fuzz") or string.find(sect, "rusty") then
				math.randomseed(time_global())
				if math.random(2) == 1 then alife():create("af_rusty_sea-urchin", pos, lv, gv) end
				if math.random(2) == 1 then alife():create("af_rusty_kristall", pos, lv, gv) end
				if math.random(2) == 1 then alife():create("af_rusty_thorn", pos, lv, gv) end
		elseif string.find(sect, "buzz") then
			if string.find(sect, "weak") then
				if math.random(6)==1 then alife():create("af_ameba_slug", pos, lv, gv) end
			elseif string.find(sect, "average") then
				if math.random(5) == 1 then alife():create("af_ameba_slime", pos, lv, gv) end
				if math.random(4) <= 1 then alife():create("af_ameba_slug", pos, lv, gv) end
			else
				if math.random(5) == 1 then alife():create("af_ameba_mica", pos, lv, gv) end
				if math.random(5) == 1 then alife():create("af_ameba_slug", pos, lv, gv) end
				if math.random(4) == 1 then alife():create("af_ameba_slime", pos, lv, gv) end
			end

elseif string.find(sect, "doggy") then
			local n=0
			math.randomseed(time_global())
			for n=1, math.random(3) do
				alife():create("dog_weak", pos, lv, gv)
			end
