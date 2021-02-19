class BotGroupMissionHospital: CustomMission
{
	
	void BotGroupMissionHospital() {}
	
	
	// Конфиги ботов
	vector BotSpawnPoint = "7280.450195 84.362503 8024.799805";				// задаем точку спавна бота	
	
	protected int m_botAcuracy = 10;											// Настройка меткости бота (чем выше число, тем чаще бот промазывает)
	
	protected int BotSolderCountMin = 2;  										// назначаем минимальное количесство ботов
	protected int BotSolderCountMax = 4;										// назначаем максимальное количесство ботов
	
	protected int botLootCountMin = 5; 											// назначаем минимальное количество лута у бота
	protected int botLootCountMax = 15; 										// назначаем максимальное количество лута у бота
	
	protected float Zone_Radius = 1100;											// Радиус триггера на игрока для появления ботов
	
	protected bool isUseCheckPoints = false;									// задаем используются ли чекпонинты true - используются, fslse - не используются
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
		
		m_BotSolder.AddCheckpoint("7243.034180 84.519814 7983.532715");
		m_BotSolder.AddCheckpoint("7226.239258 84.565941 7963.380371");
		m_BotSolder.AddCheckpoint("7214.201172 85.697540 7942.440430");
		m_BotSolder.AddCheckpoint("7248.671875 84.765587 7921.823242");
		m_BotSolder.AddCheckpoint("7292.998047 86.582817 7876.550781");
		m_BotSolder.AddCheckpoint("7307.975586 84.899994 7900.290527");
		m_BotSolder.AddCheckpoint("7327.455078 84.702477 7933.083984");
		m_BotSolder.AddCheckpoint("7376.537109 84.276505 7972.716309");
        m_BotSolder.AddCheckpoint("7370.478027 84.381439 7975.654785");
		m_BotSolder.AddCheckpoint("7360.881836 84.382492 7986.871094");
		m_BotSolder.AddCheckpoint("7335.041992 86.129578 7958.293945");
		m_BotSolder.AddCheckpoint("7310.402832 84.369980 7992.591309");
		m_BotSolder.AddCheckpoint("7266.610840 84.710007 7947.341797");
		m_BotSolder.AddCheckpoint("7244.807129 84.788940 7924.723145");
		m_BotSolder.AddCheckpoint("7214.876465 85.528152 7942.745605");
		m_BotSolder.AddCheckpoint("7231.910645 84.575623 7971.499023");
        m_BotSolder.AddCheckpoint("7286.974121 84.345253 8030.398438");
		m_BotSolder.AddCheckpoint("7322.283203 84.342506 8031.287598");
		m_BotSolder.AddCheckpoint("7331.108887 84.296539 8024.210938");
		m_BotSolder.AddCheckpoint("7331.304199 84.409805 8017.948242");
		m_BotSolder.AddCheckpoint("7361.657227 84.382507 7987.347168");      
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