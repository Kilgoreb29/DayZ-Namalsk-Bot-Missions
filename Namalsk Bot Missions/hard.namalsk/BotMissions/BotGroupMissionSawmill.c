class BotGroupMissionSawmill: CustomMission
{
	
	void BotGroupMissionSawmill() {}
	
	
	// ������� �����
	vector BotSpawnPoint = "6976.812500 40.084736 5821.953125";				// ������ ����� ������ ����	
	
	protected int m_botAcuracy = 3;											// ��������� �������� ���� (��� ���� �����, ��� ���� ��� �����������)
	
	protected int BotSolderCountMin = 1;  										// ��������� ����������� ����������� �����
	protected int BotSolderCountMax = 4;										// ��������� ������������ ����������� �����
	
	protected int botLootCountMin = 1; 											// ��������� ����������� ���������� ���� � ����
	protected int botLootCountMax = 15; 										// ��������� ������������ ���������� ���� � ����
	
	protected float Zone_Radius = 1100;											// ������ �������� �� ������ ��� ��������� �����
	
	protected bool isUseCheckPoints = true;									// ������ ������������ �� ���������� true - ������������, fslse - �� ������������
	protected bool isBotKaratist = false;										// ������ ����� �� ���� � ������� ��� ����� ������ ��������, �� ��������� ��� � �������, ���� ����� ��� ���������� ������� true
	protected bool onRespawnBot = true;											// ��������� ��� ���������� �������� ���� (true - ��������, fslse - ���������)
	protected bool canUseTrigger = true;										// ������������ ������� (true - ��������, fslse - ���������), ���� �� ������������ ������� ���� ��������� ����� ����� ������� �������
	protected int m_respawnTime = 30;											// ����� �������� ���� (���������� 30 �����)
	
	protected bool canBotSpawned = true;										// �� ��������!!!!!!!
	
	// ------------------------------- ����� �������  ------------------------------------------ //
	
	
	// ������� � ����� � ������� 
	ref TStringArray Shirt = {"GorkaEJacket_Autumn", "GorkaEJacket_Flat", "GorkaEJacket_PautRev", "GorkaEJacket_Summer"}; 					//��������� ���� ������
	ref TStringArray Jeans = {"GorkaPants_Autumn", "GorkaPants_Flat", "GorkaPants_PautRev", "GorkaPants_Summer"}; 							//��������� �����
	ref TStringArray Shoes = {"TTSKOBoots", "WorkingBoots_Beige", "CombatBoots_Beige", "CombatBoots_Black", "CombatBoots_Brown"};			//��������� �������
	ref TStringArray BackPack = {"CoyoteBag_Brown", "CoyoteBag_Green", "HuntingBag", "TortillaBag", "WaterproofBag_Green"};					//��������� ������
	ref TStringArray Vest = {"HighCapacityVest_Black", "HighCapacityVest_Olive", "HuntingVest", "PlateCarrierVest", "UKAssVest_Camo"};		//��������� ���������
	ref TStringArray Helm = {"GorkaHelmet", "Mich2001Helmet", "MotoHelmet_Black", "PumpkinHelmet", "SkateHelmet_Black"};					//��������� ���� ��� �������� ����
	ref TStringArray Gloves = {"WorkingGloves_Beige", "WorkingGloves_Black", "NBCGlovesGray", "OMNOGloves_Brown", "SurgicalGloves_Blue"};	//��������� ��������
	ref TStringArray OtherEquip = {"CivilianBelt", "MilitaryBelt"};																			//��������� �������������� ������� ������, ��� ����� ���� �� ��� ������ :)	
	
	ref TStringArray RandomLoot = {"SardinesCan", "SodaCan_Cola", "SodaCan_Kvass", "Rice", "Rope", "Screwdriver", "AmmoBox_545x39_20Rnd"};  //��������� � ����� ����� ���, ���������� �� ����������
	ref TStringArray MeleeWeap = {"WoodAxe", "FirefighterAxe", "Shovel", "Pickaxe"}; 														//��������� �������� ������
	
	// -------------------------------- ����� �������� ����  -------------------------------------------------------//

	protected EntityAI itemEnt;				// �� ��������!!!!

	// ������� �������� ���������� (����������� ��������� ���)
	void AddCeckPoint(SurvivorBotBase m_BotSolder)
	{
		m_BotSolder.SetUseCheckpoint(); // ��� ������ �� �������!
		
		m_BotSolder.AddCheckpoint("7091.590820 40.025917 5810.538574");
		m_BotSolder.AddCheckpoint("7132.389160 40.505047 5795.682129");
		m_BotSolder.AddCheckpoint("7171.875488 40.332851 5793.267578");
		m_BotSolder.AddCheckpoint("7188.827148 40.247265 5824.627441");
		m_BotSolder.AddCheckpoint("7158.460938 40.186016 5827.454102");
		m_BotSolder.AddCheckpoint("7119.429199 40.012497 5831.685059");
		m_BotSolder.AddCheckpoint("7117.577148 40.012444 5841.316406");
		m_BotSolder.AddCheckpoint("6996.102051 40.012466 5848.520020");
        m_BotSolder.AddCheckpoint("6997.617188 40.146591 5817.343262");
		m_BotSolder.AddCheckpoint("7001.918457 40.212460 5786.935059");
		m_BotSolder.AddCheckpoint("7060.882324 45.731297 5790.646484");
		m_BotSolder.AddCheckpoint("7042.174316 39.953209 5772.033691");
		m_BotSolder.AddCheckpoint("7071.958496 39.608940 5770.046387");
		m_BotSolder.AddCheckpoint("7096.888184 40.087139 5806.395996");
		m_BotSolder.AddCheckpoint("7071.540527 39.975903 5814.604980");
		m_BotSolder.AddCheckpoint("6984.874023 40.108944 5821.456543");
        m_BotSolder.AddCheckpoint("6940.479004 40.213421 5824.220703");       
	}
	// ---------------------------------- ����� ������� �������� ����������  -------------------------------------- /	
	

	
	
	// ������� �������� ������ ��� ���� (��� ����� �������� 7 ����� ������, ��������� �� ������ ����������)
	void createWeapFromBot(SurvivorBotBase m_BotSolder)
	{
		int randomWeapon = Math.RandomInt(1, 7);
			
		switch( randomWeapon )
		{	
			case 1: 
			{
				m_BotSolder.AddWeapon("M4A1"); 				//������
				m_BotSolder.AddWeaponAtt("M4_RISHndgrd");	//�����1
				m_BotSolder.AddWeaponAtt("M4_MPBttstck");	//�����2
				m_BotSolder.AddWeaponAtt("ACOGOptic");		//�����3
				break;
				//������ ��������� �� �������������, �������� ��� ������ �������� ������������� �� ��������� �� ���������
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
	// ----------------------------- ����� ������� �������� ������ ------------------------------------- //
	
	// ������� ������ ���� (��� ������ �� ������!!!)
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
	// ----------------------------- ����� ������� ������ ���� ------------------------------------- //
	
	// ----------------------------- ������� �������� ����� ----------------------------------------//
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
	// ----------------------------- ����� ������� ----------------------------------------//
	

	
	
	// ������� ������ ������ �����
	void spawnBotGroup()
	{
		int rndBotGrpCnt = Math.RandomInt(BotSolderCountMin, BotSolderCountMax);
		Print("Bots spawned! Count " + rndBotGrpCnt);
		for (int a = 0; a < rndBotGrpCnt; a++)
		{
			createBotUnit();
		}	
	}
	// --------------------------------------- ����� ������� ������ ������  --------------------------------------- //
	
	// ������� �������� �� ������
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
	// --------------------------------------- ����� ������� ��������  --------------------------------------- //
	
	// ��� ������� �������� � initBotMissions.c	
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