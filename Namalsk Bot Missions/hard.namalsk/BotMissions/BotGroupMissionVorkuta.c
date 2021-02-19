class BotGroupMissionVorkuta: CustomMission
{
	
	void BotGroupMissionVorkuta() {}
	
	
	// Конфиги ботов
	vector BotSpawnPoint = "6970.150391 15.012475 11513.415039";				// задаем точку спавна бота	
	
	protected int m_botAcuracy = 10;											// Настройка меткости бота (чем выше число, тем чаще бот промазывает)
	
	protected int BotSolderCountMin = 1;  										// назначаем минимальное количесство ботов
	protected int BotSolderCountMax = 4;										// назначаем максимальное количесство ботов
	
	protected int botLootCountMin = 1; 											// назначаем минимальное количество лута у бота
	protected int botLootCountMax = 2; 										    // назначаем максимальное количество лута у бота
	
	protected float Zone_Radius = 1100;											// Радиус триггера на игрока для появления ботов
	
	protected bool isUseCheckPoints = true;									    // задаем используются ли чекпонинты true - используются, fslse - не используются
	protected bool isBotKaratist = true;										// Задаем будут ли боты с оружием или будут дратся кулаками, по умолчанию они с оружием, если нужны без огнестрела пропиши true
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
		
		m_BotSolder.AddCheckpoint("6942.455078 16.172461 11511.031250");
		m_BotSolder.AddCheckpoint("6913.545410 16.940962 11505.585938");
		m_BotSolder.AddCheckpoint("6888.460938 15.824196 11491.372070");
		m_BotSolder.AddCheckpoint("6852.938477 15.113738 11460.416992");
		m_BotSolder.AddCheckpoint("6837.615723 15.150000 11441.915039");
		m_BotSolder.AddCheckpoint("6825.591309 15.150000 11421.253906");
		m_BotSolder.AddCheckpoint("6797.141602 15.172422 11367.168945");
		m_BotSolder.AddCheckpoint("6780.195313 15.012397 11334.058594");
        m_BotSolder.AddCheckpoint("6748.419922 14.766623 11305.406250");
		m_BotSolder.AddCheckpoint("6739.548340 15.012501 11279.093750");
		m_BotSolder.AddCheckpoint("6718.338379 15.012449 11235.573242");
		m_BotSolder.AddCheckpoint("6703.132324 15.012440 11202.651367");
		m_BotSolder.AddCheckpoint("6691.919922 15.012386 11183.533203");
		m_BotSolder.AddCheckpoint("6702.356934 15.040000 11179.284180");
		m_BotSolder.AddCheckpoint("6691.806152 15.012395 11158.658203");
		m_BotSolder.AddCheckpoint("6672.324707 15.058154 11121.547852");
        m_BotSolder.AddCheckpoint("6630.931641 15.102427 11040.266602");
		m_BotSolder.AddCheckpoint("6609.966309 15.128249 10995.850586");
		m_BotSolder.AddCheckpoint("6608.077637 15.506002 10978.742188");
		m_BotSolder.AddCheckpoint("6621.669434 15.786562 10953.997070");
		m_BotSolder.AddCheckpoint("6638.215820 16.408655 10930.502930");
		m_BotSolder.AddCheckpoint("6634.770996 16.024265 10934.900391");
		m_BotSolder.AddCheckpoint("6632.996094 16.067646 10931.628906");
		m_BotSolder.AddCheckpoint("6639.407715 16.132717 10920.497070");
		m_BotSolder.AddCheckpoint("6660.304688 16.270620 10889.107422");
		m_BotSolder.AddCheckpoint("6664.676270 16.326817 10884.067383");
		m_BotSolder.AddCheckpoint("6660.782715 16.361557 10877.958008");
		m_BotSolder.AddCheckpoint("6667.995605 16.467796 10871.325195");
		m_BotSolder.AddCheckpoint("6671.789063 16.770193 10854.535156");
		m_BotSolder.AddCheckpoint("6673.553223 17.296291 10831.338867");
		m_BotSolder.AddCheckpoint("6646.209473 19.288366 10671.090820");
		m_BotSolder.AddCheckpoint("6669.812500 18.927322 10675.843750");
        m_BotSolder.AddCheckpoint("6703.342773 17.900290 10692.912109");
		m_BotSolder.AddCheckpoint("6740.024414 16.133917 10708.203125");
		m_BotSolder.AddCheckpoint("6767.658203 16.012444 10710.097656");
		m_BotSolder.AddCheckpoint("6872.278809 17.184795 10690.301758");
		m_BotSolder.AddCheckpoint("6975.607910 16.993858 10689.542969");
		m_BotSolder.AddCheckpoint("7088.986816 15.835255 10711.598633");
		m_BotSolder.AddCheckpoint("7104.322754 15.734880 10720.286133");
		m_BotSolder.AddCheckpoint("7091.354004 15.988649 10710.573242");
        m_BotSolder.AddCheckpoint("7029.381348 21.894318 10818.112305");
		m_BotSolder.AddCheckpoint("7003.492188 19.969055 10863.375000");
		m_BotSolder.AddCheckpoint("6989.783691 15.399456 10930.115234");
		m_BotSolder.AddCheckpoint("6989.817383 15.068183 10961.392578");
		m_BotSolder.AddCheckpoint("6992.525391 15.368140 11008.543945");
		m_BotSolder.AddCheckpoint("6995.867676 15.012490 11031.634766");
		m_BotSolder.AddCheckpoint("6987.855957 15.012385 11047.938477");
		m_BotSolder.AddCheckpoint("6985.131836 14.696017 11057.839844");
		m_BotSolder.AddCheckpoint("6976.923828 14.646286 11062.868164");
		m_BotSolder.AddCheckpoint("6963.445313 14.449168 11097.099609");
		m_BotSolder.AddCheckpoint("6976.638184 15.607828 11162.941406");
		m_BotSolder.AddCheckpoint("7026.419922 15.640146 11254.957031");
		m_BotSolder.AddCheckpoint("7047.630371 15.282057 11355.570313");
		m_BotSolder.AddCheckpoint("7049.328125 15.191242 11370.089844");
		m_BotSolder.AddCheckpoint("7046.713379 15.017716 11391.631836");
		m_BotSolder.AddCheckpoint("7019.822754 15.012458 11464.166016");
		m_BotSolder.AddCheckpoint("7003.132324 15.012498 11487.623047");
		m_BotSolder.AddCheckpoint("6978.656738 15.012488 11505.809570");
		m_BotSolder.AddCheckpoint("6958.043457 15.235197 11514.971680");
		m_BotSolder.AddCheckpoint("6919.085449 16.951784 11507.546875");
		m_BotSolder.AddCheckpoint("6890.226563 15.900379 11492.579102");
        m_BotSolder.AddCheckpoint("6850.003906 15.120408 11457.537109");        
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