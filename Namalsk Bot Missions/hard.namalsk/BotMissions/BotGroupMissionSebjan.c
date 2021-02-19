class BotGroupMissionSebjan: CustomMission
{
	
	void BotGroupMissionSebjan() {}
	
	
	// Конфиги ботов
	vector BotSpawnPoint = "4991.814941 49.982082 8036.186035";				    // задаем точку спавна бота	
	
	protected int m_botAcuracy = 3;											    // Настройка меткости бота (чем выше число, тем чаще бот промазывает)
	
	protected int BotSolderCountMin = 1;  										// назначаем минимальное количесство ботов
	protected int BotSolderCountMax = 4;										// назначаем максимальное количесство ботов
	
	protected int botLootCountMin = 1; 											// назначаем минимальное количество лута у бота
	protected int botLootCountMax = 15; 										// назначаем максимальное количество лута у бота
	
	protected float Zone_Radius = 1100;											// Радиус триггера на игрока для появления ботов
	
	protected bool isUseCheckPoints = true;								        // задаем используются ли чекпонинты true - используются, fslse - не используются
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
		
		m_BotSolder.AddCheckpoint("4974.858398 40.853798 8103.625000");
		m_BotSolder.AddCheckpoint("4948.172852 40.785980 8114.238281");
		m_BotSolder.AddCheckpoint("4929.498535 40.005089 8126.958984");
		m_BotSolder.AddCheckpoint("4907.101074 40.403717 8147.295410");
		m_BotSolder.AddCheckpoint("4901.551758 44.938217 8183.819336");
		m_BotSolder.AddCheckpoint("4891.566895 47.711575 8234.874023");
		m_BotSolder.AddCheckpoint("4973.914551 41.044743 8252.679688");
		m_BotSolder.AddCheckpoint("4992.000977 41.432816 8270.861328");
        m_BotSolder.AddCheckpoint("5031.735352 37.549438 8370.783203");
		m_BotSolder.AddCheckpoint("5071.895020 38.051880 8353.168945");
		m_BotSolder.AddCheckpoint("5095.800293 39.758022 8326.958984");
		m_BotSolder.AddCheckpoint("5101.825195 39.297352 8304.537109");
		m_BotSolder.AddCheckpoint("5099.848145 41.219040 8221.867188");
		m_BotSolder.AddCheckpoint("5099.848145 41.219040 8221.867188");
		m_BotSolder.AddCheckpoint("5083.213379 43.702751 8224.099609");
		m_BotSolder.AddCheckpoint("5083.213379 43.702751 8224.099609");
        m_BotSolder.AddCheckpoint("5088.596191 39.454189 8220.691406");
		m_BotSolder.AddCheckpoint("5099.848145 41.219040 8221.867188");
		m_BotSolder.AddCheckpoint("5095.425781 39.634716 8199.998047");
		m_BotSolder.AddCheckpoint("5090.819824 38.569923 8132.604980");
		m_BotSolder.AddCheckpoint("5090.947266 38.145584 8138.755859");
		m_BotSolder.AddCheckpoint("5049.090820 39.172497 8137.445801");
		m_BotSolder.AddCheckpoint("5019.068359 39.172497 8137.056641");
		m_BotSolder.AddCheckpoint("5018.434082 39.182426 8147.023438");
		m_BotSolder.AddCheckpoint("4980.601074 39.182434 8147.312500");
		m_BotSolder.AddCheckpoint("4979.312012 41.103840 8092.491699");
		m_BotSolder.AddCheckpoint("4987.741699 44.139984 8070.425293");
		m_BotSolder.AddCheckpoint("4992.488281 49.970394 8037.968262");
		m_BotSolder.AddCheckpoint("4972.661133 49.762680 8037.582031");
		m_BotSolder.AddCheckpoint("4969.875000 49.818142 8030.490723");
		m_BotSolder.AddCheckpoint("4968.457520 49.843056 8010.871094");
		m_BotSolder.AddCheckpoint("4964.206055 49.307659 8001.809570");
        m_BotSolder.AddCheckpoint("4990.626953 63.176086 7958.915039");
		m_BotSolder.AddCheckpoint("5064.153320 56.918472 7970.674805");
		m_BotSolder.AddCheckpoint("5037.809570 50.012432 7952.637695");
		m_BotSolder.AddCheckpoint("5037.986816 50.012363 7947.397949");
		m_BotSolder.AddCheckpoint("5006.363281 50.012348 7942.994141");
		m_BotSolder.AddCheckpoint("4929.809570 50.012470 7942.680664");
		m_BotSolder.AddCheckpoint("4918.290039 50.012424 7946.430664");
		m_BotSolder.AddCheckpoint("4902.148438 50.012470 7944.865234");
        m_BotSolder.AddCheckpoint("4955.829590 50.012497 7942.494629");
		m_BotSolder.AddCheckpoint("4954.205566 51.994335 7979.884766");
		m_BotSolder.AddCheckpoint("4881.034180 50.012497 7974.857422");
		m_BotSolder.AddCheckpoint("4798.070313 50.032051 7984.558105");
		m_BotSolder.AddCheckpoint("4796.946289 51.142109 8021.708008");
		m_BotSolder.AddCheckpoint("4830.809570 49.439205 8009.053711");
		m_BotSolder.AddCheckpoint("4859.000000 50.012497 8015.721191");
		m_BotSolder.AddCheckpoint("4895.178711 50.012463 8017.410645");
		m_BotSolder.AddCheckpoint("4896.080078 50.012466 8010.934082");
		m_BotSolder.AddCheckpoint("4970.924316 49.875126 8011.958008");
		m_BotSolder.AddCheckpoint("4970.146973 49.765938 8035.674316");
        m_BotSolder.AddCheckpoint("4993.642578 43.294018 8064.602539");       
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