class BotGroupMissionTown: CustomMission
{
	
	void BotGroupMissionTown() {}
	
	
	// ������� �����
	vector BotSpawnPoint = "5281.607422 38.288006 8658.205078";				    // ������ ����� ������ ����	
	
	protected int m_botAcuracy = 4;											    // ��������� �������� ���� (��� ���� �����, ��� ���� ��� �����������)
	
	protected int BotSolderCountMin = 1;  										// ��������� ����������� ����������� �����
	protected int BotSolderCountMax = 4;										// ��������� ������������ ����������� �����
	
	protected int botLootCountMin = 1; 											// ��������� ����������� ���������� ���� � ����
	protected int botLootCountMax = 10; 										// ��������� ������������ ���������� ���� � ����
	
	protected float Zone_Radius = 1100;											// ������ �������� �� ������ ��� ��������� �����
	
	protected bool isUseCheckPoints = true;									    // ������ ������������ �� ���������� true - ������������, fslse - �� ������������
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
		
		m_BotSolder.AddCheckpoint("5271.339844 37.482445 8641.515625");
		m_BotSolder.AddCheckpoint("5262.821289 37.183338 8636.477539");
		m_BotSolder.AddCheckpoint("5222.345215 36.156818 8634.916016");
		m_BotSolder.AddCheckpoint("5222.304688 31.127634 8601.753906");
		m_BotSolder.AddCheckpoint("5214.386230 31.102137 8575.507813");
		m_BotSolder.AddCheckpoint("5208.281738 31.067461 8558.092773");
		m_BotSolder.AddCheckpoint("5200.950684 31.026949 8554.673828");
		m_BotSolder.AddCheckpoint("5182.625000 31.671080 8538.781250");
        m_BotSolder.AddCheckpoint("5173.990234 31.022501 8524.641602");
		m_BotSolder.AddCheckpoint("5192.090820 31.022421 8546.596680");
		m_BotSolder.AddCheckpoint("5209.541016 31.058950 8559.647461");
		m_BotSolder.AddCheckpoint("5222.979004 31.172161 8601.794922");
		m_BotSolder.AddCheckpoint("5222.898926 36.104702 8634.510742");
		m_BotSolder.AddCheckpoint("5226.229492 42.580753 8665.491211");
		m_BotSolder.AddCheckpoint("5225.929199 45.451752 8690.817383");
		m_BotSolder.AddCheckpoint("5222.693848 36.103897 8634.528320");
        m_BotSolder.AddCheckpoint("5257.913086 37.028313 8635.056641");
		m_BotSolder.AddCheckpoint("5270.334961 37.431683 8640.051758");
		m_BotSolder.AddCheckpoint("5283.090820 38.246288 8659.287109");      
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