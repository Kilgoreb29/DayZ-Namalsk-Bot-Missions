class BotGroupMissionNorinsk: CustomMission
{
	
	void BotGroupMissionNorinsk() {}
	
	
	// ������� �����
	vector BotSpawnPoint = "3914.257080 53.032776 7559.960449";				// ������ ����� ������ ����	
	
	protected int m_botAcuracy = 2;											// ��������� �������� ���� (��� ���� �����, ��� ���� ��� �����������)
	
	protected int BotSolderCountMin = 1;  										// ��������� ����������� ����������� �����
	protected int BotSolderCountMax = 4;										// ��������� ������������ ����������� �����
	
	protected int botLootCountMin = 1; 											// ��������� ����������� ���������� ���� � ����
	protected int botLootCountMax = 10; 										// ��������� ������������ ���������� ���� � ����
	
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
		
		m_BotSolder.AddCheckpoint("3953.185791 52.314030 7505.213867");
		m_BotSolder.AddCheckpoint("3905.485107 53.181801 7447.955566");
		m_BotSolder.AddCheckpoint("3889.877197 53.143814 7447.892090");
		m_BotSolder.AddCheckpoint("3878.618164 53.108856 7454.314941");
		m_BotSolder.AddCheckpoint("3880.469971 53.108803 7455.166504");
		m_BotSolder.AddCheckpoint("3862.997314 53.012428 7465.582520");
		m_BotSolder.AddCheckpoint("3853.801514 53.012489 7469.177246");
		m_BotSolder.AddCheckpoint("3845.147949 53.012466 7481.142578");
        m_BotSolder.AddCheckpoint("3850.710449 53.138237 7489.721191");
		m_BotSolder.AddCheckpoint("3863.081299 53.012493 7506.235352");
		m_BotSolder.AddCheckpoint("3898.602295 54.798580 7550.941895");
		m_BotSolder.AddCheckpoint("3913.841064 53.036041 7562.163574");
		m_BotSolder.AddCheckpoint("3916.337158 53.024059 7580.455078");
		m_BotSolder.AddCheckpoint("3951.648682 53.012497 7631.479980");
		m_BotSolder.AddCheckpoint("3984.548340 52.999996 7671.662598");
		m_BotSolder.AddCheckpoint("4047.351074 52.745655 7632.393066");
        m_BotSolder.AddCheckpoint("4012.968018 62.797588 7596.378418");
		m_BotSolder.AddCheckpoint("3957.320557 53.871117 7534.853516");
		m_BotSolder.AddCheckpoint("3906.836426 53.181767 7448.325684");
		m_BotSolder.AddCheckpoint("3877.626465 52.865837 7453.308594");
		m_BotSolder.AddCheckpoint("3860.727295 53.899281 7470.547363");
		m_BotSolder.AddCheckpoint("3875.650146 52.893967 7485.292969");
		m_BotSolder.AddCheckpoint("3886.125000 50.818459 7502.388184");
		m_BotSolder.AddCheckpoint("3872.084229 53.012455 7508.203613");
		m_BotSolder.AddCheckpoint("3836.239990 57.911572 7484.284180");
		m_BotSolder.AddCheckpoint("3873.876221 53.012394 7508.135254");
		m_BotSolder.AddCheckpoint("3913.736572 53.035919 7560.875977");       
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