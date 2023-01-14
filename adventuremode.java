@EventHandler
	public void onCpUse(PlayerMoveEvent e) {
		Player player = e.getPlayer();
		if(Main.main.state != Gamestate.JUMP) return;
		if(!Main.main.alive.contains(player)) return;
		Location loc = e.getPlayer().getLocation();
		  loc.setY(loc.getY() -1);
		  Block standingOnBlock = loc.getBlock();
		  int currentCP = Main.main.checkpointTracker.get(player);
			int nextCP = currentCP+1;
		  if(standingOnBlock.getType() == Material.EMERALD_BLOCK) {
			  Main.main.lm.setLocation(Main.main.map + "x" + nextCP + "x" + player.getName(), player.getLocation());
			  standingOnBlock.setType(Material.BEDROCK);
				giveCPEquip(player, nextCP);
					Main.main.checkpointTracker.put(player, nextCP);
					Main.main.scoreboard.setIngameScoreboard(player);
					player.sendMessage(Main.main.pr + "�aDu hast den " + nextCP + ". Checkpoint erreicht!");
					if(Main.main.particleTracker.containsKey(player)) {
						player.spawnParticle(Main.main.particleTracker.get(player), player.getLocation(), 10);
					}
			 		player.playSound(player.getLocation(), Sound.ENTITY_PLAYER_LEVELUP, 10, 1);
		  }
	}
	public void giveCPEquip(Player p, int cp) {
		Inventory i = p.getInventory();
		ItemStack cp1Helmet = Main.main.utils.create(Material.LEATHER_HELMET, 1);
		ItemStack cp1Chest = Main.main.utils.create(Material.LEATHER_CHESTPLATE, 1);
		ItemStack cp1Leggings = Main.main.utils.create(Material.LEATHER_LEGGINGS, 1);
		ItemStack cp1Boots = Main.main.utils.create(Material.LEATHER_BOOTS, 1);
		
		ItemStack cp2Sword = Main.main.utils.createSharp1Item(Material.STONE_SWORD, 1);
		
		ItemStack cp3Apples = Main.main.utils.create(Material.GOLDEN_APPLE, 3);
		
		ItemStack cp4Chest = Main.main.utils.create(Material.CHAINMAIL_CHESTPLATE, 1);
		ItemStack cp4Leggings = Main.main.utils.create(Material.CHAINMAIL_LEGGINGS, 1);
		
		ItemStack cp5Helmet = Main.main.utils.create(Material.IRON_HELMET, 1);
		ItemStack cp5Boots = Main.main.utils.create(Material.IRON_BOOTS, 1);
		
		//6 Add extra Herzen
		
		ItemStack cp7Sword = Main.main.utils.create(Material.DIAMOND_SWORD, 1);
		
		ItemStack cp8Sword = Main.main.utils.create(Material.SHIELD, 1);
		
		
		ItemStack cp1Helmet1 = Main.main.utils.create(Material.DIAMOND_HELMET, 1);
		ItemStack cp1Chest1 = Main.main.utils.create(Material.DIAMOND_CHESTPLATE, 1);
		ItemStack cp1Leggings1 = Main.main.utils.create(Material.DIAMOND_LEGGINGS, 1);
		ItemStack cp1Boots1 = Main.main.utils.create(Material.DIAMOND_BOOTS, 1);
		
		ItemStack cp2Sword1 = Main.main.utils.createSharp1Item(Material.DIAMOND_SWORD, 1);
		
		ItemStack cp3Apples1 = Main.main.utils.create(Material.SHIELD, 1);
		
		ItemStack cp4Leggings1 = Main.main.utils.create(Material.NETHERITE_LEGGINGS, 1);
		
		ItemStack cp5Helmet1 = Main.main.utils.create(Material.NETHERITE_HELMET, 1);
		ItemStack cp5Boots1 = Main.main.utils.create(Material.NETHERITE_BOOTS, 1);
		
		//6 Add extra Herzen
		
		ItemStack cp7Sword1 = Main.main.utils.create(Material.NETHERITE_CHESTPLATE, 1);
		
		ItemStack cp8Sword1 = Main.main.utils.createSharp1Item(Material.NETHERITE_SWORD, 1);
		
		
		ItemStack cp1Helmet2 = Main.main.utils.create(Material.GOLDEN_HELMET, 1);
		ItemStack cp1Chest2 = Main.main.utils.create(Material.GOLDEN_CHESTPLATE, 1);
		ItemStack cp1Leggings2 = Main.main.utils.create(Material.GOLDEN_LEGGINGS, 1);
		ItemStack cp1Boots2 = Main.main.utils.create(Material.GOLDEN_BOOTS, 1);
		
		ItemStack cp2Sword2 = Main.main.utils.createSharp1Item(Material.STONE_SWORD, 1);
		
		ItemStack cp3Apples2 = Main.main.utils.create(Material.GOLDEN_APPLE, 3);
		ItemStack cp3Apple2 = Main.main.utils.create(Material.SHIELD, 1);
		
		ItemStack cp4Leggings2 = Main.main.utils.create(Material.IRON_LEGGINGS, 1);
		
		ItemStack cp5Helmet2 = Main.main.utils.create(Material.IRON_HELMET, 1);
		ItemStack cp5Boots2 = Main.main.utils.create(Material.IRON_BOOTS, 1);
		
		//6 Add extra Herzen
		
		ItemStack cp7Sword2 = Main.main.utils.create(Material.IRON_CHESTPLATE, 1);
		
		ItemStack cp8Sword2 = Main.main.utils.createSharp1Item(Material.IRON_SWORD, 1);
		
		
		
		if(!Main.main.random) {
		if(Main.main.rn ==0) {
		if(cp == 1) {
			i.addItem(cp1Helmet);
			i.addItem(cp1Chest);
			i.addItem(cp1Leggings);
			i.addItem(cp1Boots);
		}else if(cp == 2) {
			i.addItem(cp2Sword);
		}else if(cp == 3) {
			i.addItem(cp3Apples);
		}else if(cp == 4) {
			i.addItem(cp4Chest);
			i.addItem(cp4Leggings);
		}else if(cp == 5) {
			i.addItem(cp5Helmet);
			i.addItem(cp5Boots);
		}else if(cp == 6) {
			p.setMaxHealth(24);
			p.sendMessage(Main.main.pr + "�aDu hast zwei Extraherzen erhalten!");
		}else if(cp == 7) {
			i.addItem(cp7Sword);
		}else if(cp == 8) {
			i.addItem(cp8Sword);
			if(Main.main.fallTracker.get(p) == 0) {
				p.sendMessage(Main.main.pr + "Du hast das Ziel ohne JumpFail erreicht!");
				p.getInventory().addItem(Main.main.utils.create(Material.DIAMOND_HELMET, 1));
			}
			Bukkit.broadcastMessage(Main.main.pr + "�5" + p.getName() + " �a hat das Ziel erreicht!");
			Main.main.cd.cancelIngameTask();
			Main.main.cd.startDeathmatchCD();
		}
	}else if(Main.main.rn == 1) {
		if(cp == 1) {
			i.addItem(cp1Helmet1);
			i.addItem(cp1Chest1);
			i.addItem(cp1Leggings1);
			i.addItem(cp1Boots1);
		}else if(cp == 2) {
			i.addItem(cp2Sword1);
		}else if(cp == 3) {
			i.addItem(cp3Apples1);
		}else if(cp == 4) {
			i.addItem(cp4Leggings1);
		}else if(cp == 5) {
			i.addItem(cp5Helmet1);
			i.addItem(cp5Boots1);
		}else if(cp == 6) {
			p.setMaxHealth(24);
			p.sendMessage(Main.main.pr + "�aDu hast zwei Extraherzen erhalten!");
		}else if(cp == 7) {
			i.addItem(cp7Sword1);
		}else if(cp == 8) {
			i.addItem(cp8Sword1);
			if(Main.main.fallTracker.get(p) == 0) {
				p.sendMessage(Main.main.pr + "Du hast das Ziel ohne JumpFail erreicht!");
				p.getInventory().addItem(Main.main.utils.create(Material.GOLDEN_APPLE, 10));
			}
			Bukkit.broadcastMessage(Main.main.pr + "�5" + p.getName() + " �a hat das Ziel erreicht!");
			Main.main.cd.cancelIngameTask();
			Main.main.cd.startDeathmatchCD();
		}
	}else if(Main.main.rn == 2) {
		if(cp == 1) {
			i.addItem(cp1Helmet2);
			i.addItem(cp1Chest2);
			i.addItem(cp1Leggings2);
			i.addItem(cp1Boots2);
		}else if(cp == 2) {
			i.addItem(cp2Sword2);
		}else if(cp == 3) {
			i.addItem(cp3Apples2);
			i.addItem(cp3Apple2);
		}else if(cp == 4) {
			i.addItem(cp4Leggings2);
		}else if(cp == 5) {
			i.addItem(cp5Helmet2);
			i.addItem(cp5Boots2);
		}else if(cp == 6) {
			p.setMaxHealth(24);
			p.sendMessage(Main.main.pr + "�aDu hast zwei Extraherzen erhalten!");
		}else if(cp == 7) {
			i.addItem(cp7Sword2);
		}else if(cp == 8) {
			i.addItem(cp8Sword2);
			if(Main.main.fallTracker.get(p) == 0) {
				p.sendMessage(Main.main.pr + "Du hast das Ziel ohne JumpFail erreicht!");
				p.getInventory().addItem(Main.main.utils.create(Material.GOLDEN_APPLE, 10));
			}
			Bukkit.broadcastMessage(Main.main.pr + "�5" + p.getName() + " �a hat das Ziel erreicht!");
			Main.main.cd.cancelIngameTask();
			Main.main.cd.startDeathmatchCD();
		}	
	}
		}else {
		    Random random = new Random();
		    List<Material> materials = Arrays.asList(Material.values());
		    int size = materials.size()-1;
		    Material ran = materials.get(random.nextInt(size));
		    p.getInventory().addItem(new ItemStack(ran, 1));
		    if(cp == 8) {
		    	if(Main.main.fallTracker.get(p) == 0) {
					p.sendMessage(Main.main.pr + "Du hast das Ziel ohne JumpFail erreicht!");
					p.getInventory().addItem(Main.main.utils.create(Material.DIAMOND_HELMET, 1));
				}
				Bukkit.broadcastMessage(Main.main.pr + "�5" + p.getName() + " �a hat das Ziel erreicht!");
				Main.main.cd.cancelIngameTask();
				Main.main.cd.startDeathmatchCD();
		    }
		}
	}
