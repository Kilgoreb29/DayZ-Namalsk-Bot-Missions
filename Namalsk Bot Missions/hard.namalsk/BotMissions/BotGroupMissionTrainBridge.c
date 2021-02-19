class BotGroupMissionTrainBridge: CustomMission
{
	
	void BotGroupMissionTrainBridge() {}
	
	
	// Конфиги ботов
	vector BotSpawnPoint = "4849.544922 41.012497 6069.519531";				// задаем точку спавна бота	
	
	protected int m_botAcuracy = 4;											// Настройка меткости бота (чем выше число, тем чаще бот промазывает)
	
	protected int BotSolderCountMin = 1;  										// назначаем минимальное количесство ботов
	protected int BotSolderCountMax = 5;										// назначаем максимальное количесство ботов
	
	protected int botLootCountMin = 1; 											// назначаем минимальное количество лута у бота
	protected int botLootCountMax = 15; 										// назначаем максимальное количество лута у бота
	
	protected float Zone_Radius = 1100;											// Радиус триггера на игрока для появления ботов
	
	protected bool isUseCheckPoints = true;									// задаем используются ли чекпонинты true - используются, fslse - не используются
	protected bool isBotKaratist = false;										// Задаем будут ли боты с оружием или будут дратся кулаками, по умолчанию они с оружием, если нужны без огнестрела пропиши true
	protected bool onRespawnBot = true;											// Включение или отключение респавна бота (true - включено, fslse - выключено)
	protected bool canUseTrigger = true;										// Использовать триггер (true - включено, fslse - выключено), если не используется триггер боты спавнятся сразу после запуска сервера
	protected int m_respawnTime = 30;											// Время респавна бота (выставлено 30 минут)
	
	protected bool canBotSpawned = true;										// Не изменять!!!!!!!
	
	// ------------------------------- конец конфига  ------------------------------------------ //
	
	
	// Массивы с лутом и одеждой 
	ref TStringArray Shirt = {"GorkaEJacket_Autumn", "GorkaEJacket_Flat", "GorkaEJacket_PautRev", "GorkaEJacket_Summer"}; 					//Добавляем верх одежды
	ref TStringArray Jeans = {"GorkaPants_Autumn", "GorkaPants_Flat", "GorkaPants_PautRev", "GorkaPants_Summer"}; 							//Добавляем штаны
	ref TStringArray Shoes = {"TTSKOBoots", "WorkingBoots_Beige", "CombatBoots_Beige", "CombatBoots_Black", "CombatBoots_Brown"};			//Добавляем ботинки
	ref TStringArray BackPack = {"CoyoteBag_Brown", "CoyoteBag_Green", "HuntingBag", "TortillaBag", "WaterproofBag_Green"};					//Добавляем Рюкзак
	ref TStringArray Vest = {"HighCapacityVest_Black", "HighCapacityVest_Olive", "HuntingVest", "PlateCarrierVest", "UKAssVest_Camo"};		//Добавляем разгрузку
	ref TStringArray Helm = {"GorkaHelmet", "Mich2001Helmet", "MotoHelmet_Black", "PumpkinHelmet", "SkateHelmet_Black"};					//Добавляем шлем или головной убор
	ref TStringArray Gloves = {"WorkingGloves_Beige", "WorkingGloves_Black", "NBCGlovesGray", "OMNOGloves_Brown", "SurgicalGloves_Blue"};	//Добавляем перчатки
	ref TStringArray OtherEquip = {"CivilianBelt", "MilitaryBelt"};																			//Добавляем дополнительный элемент одежды, это может быть всё что угодно :)	
	
	ref TStringArray RandomLoot = {"SardinesCan", "SodaCan_Cola", "SodaCan_Kvass", "Rice", "Rope", "Screwdriver", "AmmoBox_545x39_20Rnd"};  //Добавляем в масив любой лут, количество не ограничено
	ref TStringArray MeleeWeap = {"WoodAxe", "FirefighterAxe", "Shovel", "Pickaxe"}; 														//Добавляем холодное оружие
	
	// -------------------------------- конец массивов лута  -------------------------------------------------------//

	protected EntityAI itemEnt;				// Не изменять!!!!

	// Функция создания чекпоинтов (прописываем чекпоинты тут)
	void AddCeckPoint(SurvivorBotBase m_BotSolder)
	{
		m_BotSolder.SetUseCheckpoint(); // Эту строку не трогаем!
		
		m_BotSolder.AddCheckpoint("4846.509277 41.012474 6094.739258");
		m_BotSolder.AddCheckpoint("4847.728516 41.012451 6113.430176");
		m_BotSolder.AddCheckpoint("4847.726074 41.012497 6139.814941");
		m_BotSolder.AddCheckpoint("4847.932129 41.000004 6153.787598");
		m_BotSolder.AddCheckpoint("4844.810059 41.012436 6177.948730");
		m_BotSolder.AddCheckpoint("4842.394043 41.012497 6205.859863");
		m_BotSolder.AddCheckpoint("4843.014160 41.012497 6242.996094");
		m_BotSolder.AddCheckpoint("4847.718262 41.012493 6268.541504");
        m_BotSolder.AddCheckpoint("4850.964355 40.999989 6285.254883");
		m_BotSolder.AddCheckpoint("4806.013184 40.700836 6286.600098");
		m_BotSolder.AddCheckpoint("4807.246582 41.010422 6176.323242");
		m_BotSolder.AddCheckpoint("4831.040527 41.853630 6143.680176");
		m_BotSolder.AddCheckpoint("4848.963379 41.012444 6147.674316");
		m_BotSolder.AddCheckpoint("4856.801758 41.012497 6143.590820");
		m_BotSolder.AddCheckpoint("4886.317383 41.012451 6154.294434");
		m_BotSolder.AddCheckpoint("4892.912598 41.012440 6172.614258");
        m_BotSolder.AddCheckpoint("4890.245605 41.012478 6188.380371");
		m_BotSolder.AddCheckpoint("4888.280762 41.012447 6189.497559");
		m_BotSolder.AddCheckpoint("4873.854492 41.012474 6188.542969");
		m_BotSolder.AddCheckpoint("4843.204590 41.012497 6186.963867");      
	}
	// ---------------------------------- Конец функции создания чекпоинтов  -------------------------------------- /	
	

	
	
	// Функция создания оружия для бота (тут можно добавить 7 вмдов оружия, вписываем по своему усмотрению)
	void createWeapFromBot(SurvivorBotBase m_BotSolder)
	{
		int randomWeapon = Math.RandomInt(1, 7);
			
		switch( randomWeapon )
		{	
			case 1: 
			{
				m_BotSolder.AddWeapon("M4A1"); 				//оружие
				m_BotSolder.AddWeaponAtt("M4_RISHndgrd");	//Обвес1
				m_BotSolder.AddWeaponAtt("M4_MPBttstck");	//Обвес2
				m_BotSolder.AddWeaponAtt("ACOGOptic");		//Обвес3
				break;
				//Обвесы добовляем по необходимости, магазины для оружия выдаются автоматически их добовлять не требуется
			}
				
			case 2: 
			{
				m_BotSolder.AddWeapon("AKM");
				m_BotSolder.AddWeaponAtt("AK_WoodBttstck");
				m_BotSolder.AddWeaponAtt("AK_WoodHndgrd");
				break;
			}
				
			case 3: 
			{
				m_BotSolder.AddWeapon("AKM");
				m_BotSolder.AddWeaponAtt("AK_WoodBttstck");
				m_BotSolder.AddWeaponAtt("AK_WoodHndgrd");
				break;
			}
				
			case 4: 
			{
				m_BotSolder.AddWeapon("SVD");
				break;
			}
				
			case 5: 
			{
				m_BotSolder.AddWeapon("M4A1"); 	
				m_BotSolder.AddWeaponAtt("M4_RISHndgrd");	
				m_BotSolder.AddWeaponAtt("M4_MPBttstck");	
				m_BotSolder.AddWeaponAtt("ACOGOptic");		
				break;
			}
				
			case 6: 
			{
				m_BotSolder.AddWeapon("AKM");
				m_BotSolder.AddWeaponAtt("AK_WoodBttstck");
				m_BotSolder.AddWeaponAtt("AK_WoodHndgrd");
				break;
			}
				
			case 7: 
			{
				m_BotSolder.AddWeapon("AKM");
				m_BotSolder.AddWeaponAtt("AK_WoodBttstck");
				m_BotSolder.AddWeaponAtt("AK_WoodHndgrd");
				break;
			}
		}		
	}
	// ----------------------------- Конец функции создания оружия ------------------------------------- //
	
	// Функция спавна бота (тут ничего не меняем!!!)
	void createBotUnit()
	{
		private SurvivorBotBase m_BotSolder;
		
		float bspX = BotSpawnPoint[0];
		float bspY = BotSpawnPoint[2];
		
		vector botSpPos = Vector(bspX + Math.RandomInt(1, 5), BotSpawnPoint[1], bspY + Math.RandomInt(1, 5));
				
		m_BotSolder = SurvivorBotBase.Cast(GetGame().CreateObject("BotM_Mirek", botSpPos));
		
		
		if (isBotKaratist)
		{
			m_BotSolder.GetHumanInventory().CreateInHands(MeleeWeap.GetRandomElement());
		}
		else
		{
			createWeapFromBot(m_BotSolder);
		}
		
		m_BotSolder.GetInventory().CreateInInventory(Shirt.GetRandomElement());
		m_BotSolder.GetInventory().CreateInInventory(Jeans.GetRandomElement());
		m_BotSolder.GetInventory().CreateInInventory(Shoes.GetRandomElement());
		m_BotSolder.GetInventory().CreateInInventory(BackPack.GetRandomElement());
		m_BotSolder.GetInventory().CreateInInventory(Vest.GetRandomElement());
		m_BotSolder.GetInventory().CreateInInventory(Helm.GetRandomElement());
		m_BotSolder.GetInventory().CreateInInventory(Gloves.GetRandomElement());			
		m_BotSolder.GetInventory().CreateInInventory(OtherEquip.GetRandomElement());
			
		int rndLootCnt = Math.RandomInt(botLootCountMin, botLootCountMax);
			
		for (int i = 0; i < rndLootCnt; i++)
		{
			itemEnt = m_BotSolder.GetInventory().CreateInInventory(RandomLoot.GetRandomElement());
			if (itemEnt)
			{
				int rndHlt = Math.RandomInt(55,100);
				itemEnt.SetHealth("","",rndHlt);
			}
		}

		m_BotSolder.SetAcuracy(m_botAcuracy);
		
		if (isUseCheckPoints) 
			AddCeckPoint(m_BotSolder);
	
		
		if (m_BotSolder.IsAlive() && m_BotSolder && onRespawnBot)
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(respawnBotUnit, m_respawnTime * 60000, true, m_BotSolder);
	}
	// ----------------------------- Конец функции спавна бота ------------------------------------- //
	
	// ----------------------------- Функция респавна ботов ----------------------------------------//
	private void respawnBotUnit(SurvivorBotBase m_Bot)
	{
		if (onRespawnBot && m_Bot.IsRespawned())
		{
			if (!m_Bot.IsAlive())
			{
				Print("Respawn killed bot start!" + m_Bot);
				createBotUnit();
				m_Bot.SetRespawned( false );
			}		
		}		
	}
	// ----------------------------- Конец функции ----------------------------------------//
	

	
	
	// Функция спавна группы ботов
	void spawnBotGroup()
	{
		int rndBotGrpCnt = Math.RandomInt(BotSolderCountMin, BotSolderCountMax);
		Print("Bots spawned! Count " + rndBotGrpCnt);
		for (int a = 0; a < rndBotGrpCnt; a++)
		{
			createBotUnit();
		}	
	}
	// --------------------------------------- Конец функции спавна группы  --------------------------------------- //
	
	// Функция триггера на игрока
	void TriggerPlayers()
	{  
		ref array<Man> players = new array<Man>;
		GetGame().GetPlayers( players );
				
		if (canBotSpawned)
		{	
			for ( int u = 0; u < players.Count(); u++ )
			{
					
				PlayerBase player;
				Class.CastTo(player, players.Get(u));
				vector pos = player.GetPosition();
				float dist = vector.Distance( pos, BotSpawnPoint );
				
				if ( dist < Zone_Radius ) 
				{
					spawnBotGroup();
					GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).Remove(TriggerPlayers);			
				} 
			}
		}
	} 
	// --------------------------------------- Конец функции триггера  --------------------------------------- //
	
	// Эту функцию вызываем в initBotMissions.c	
	void StartMissionAI()
	{
		Print("Start mission bot");
		if (canUseTrigger)
		{
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(TriggerPlayers, 5000, true);			
		}
		else
		{
			spawnBotGroup();
		}
	}
	
}