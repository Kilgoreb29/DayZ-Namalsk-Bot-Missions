class BotGroupMissionVorkuta1: CustomMission
{
	
	void BotGroupMissionVorkuta1() {}
	
	
	// Конфиги ботов
	vector BotSpawnPoint = "7109.185547 15.751101 10733.058594";				// задаем точку спавна бота	
	
	protected int m_botAcuracy = 4;											    // Настройка меткости бота (чем выше число, тем чаще бот промазывает)
	
	protected int BotSolderCountMin = 1;  										// назначаем минимальное количесство ботов
	protected int BotSolderCountMax = 4;										// назначаем максимальное количесство ботов
	
	protected int botLootCountMin = 1; 											// назначаем минимальное количество лута у бота
	protected int botLootCountMax = 7; 										    // назначаем максимальное количество лута у бота
	
	protected float Zone_Radius = 1100;											// Радиус триггера на игрока для появления ботов
	
	protected bool isUseCheckPoints = true;									    // задаем используются ли чекпонинты true - используются, fslse - не используются
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
		
		m_BotSolder.AddCheckpoint("7109.353027 15.772488 10756.753906");
		m_BotSolder.AddCheckpoint("7112.735840 15.772423 10778.648438");
		m_BotSolder.AddCheckpoint("7122.936523 15.740318 10789.949219");
		m_BotSolder.AddCheckpoint("7135.728516 15.587986 10793.923828");
		m_BotSolder.AddCheckpoint("7155.009766 15.730593 10789.121094");
		m_BotSolder.AddCheckpoint("7178.262207 15.752735 10793.943359");
		m_BotSolder.AddCheckpoint("7194.295410 16.059547 10813.890625");
		m_BotSolder.AddCheckpoint("7202.861816 16.190676 10818.647461");
        m_BotSolder.AddCheckpoint("7254.350098 15.588411 10822.825195");
		m_BotSolder.AddCheckpoint("7267.893555 15.056947 10833.528320");
		m_BotSolder.AddCheckpoint("7272.371582 15.018264 10848.293945");
		m_BotSolder.AddCheckpoint("7265.406738 15.133471 10863.338867");
		m_BotSolder.AddCheckpoint("7249.807129 14.076641 10881.219727");
		m_BotSolder.AddCheckpoint("7231.788574 12.395926 10899.273438");
		m_BotSolder.AddCheckpoint("7223.045410 12.374148 10911.127930");
		m_BotSolder.AddCheckpoint("7182.395020 12.641771 10896.208984");
        m_BotSolder.AddCheckpoint("7146.810547 13.239653 10892.461914");
		m_BotSolder.AddCheckpoint("7131.335449 14.041796 10897.578125");
		m_BotSolder.AddCheckpoint("7086.792969 14.505552 10931.849609");
		m_BotSolder.AddCheckpoint("7072.091797 14.798700 10942.928711");
		m_BotSolder.AddCheckpoint("7026.568359 15.356735 10951.066406");
		m_BotSolder.AddCheckpoint("6988.554199 15.014146 10945.368164");
		m_BotSolder.AddCheckpoint("6997.472168 18.941292 10888.188477");
		m_BotSolder.AddCheckpoint("7003.887207 19.941807 10864.295898");
		m_BotSolder.AddCheckpoint("7026.050293 21.894438 10822.037109");
		m_BotSolder.AddCheckpoint("7092.473145 16.042807 10710.384766");      
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