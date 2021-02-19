#include "$CurrentDir:\\mpmissions\\CHANGEME\\BotMissions\\BotGroupMissionFactory2.c" 
#include "$CurrentDir:\\mpmissions\\CHANGEME\\BotMissions\\BotGroupMissionBridge.c" 
#include "$CurrentDir:\\mpmissions\\CHANGEME\\BotMissions\\BotGroupMissionFactory.c" 
#include "$CurrentDir:\\mpmissions\\CHANGEME\\BotMissions\\BotGroupMissionHospital.c" 
#include "$CurrentDir:\\mpmissions\\CHANGEME\\BotMissions\\BotGroupMissionBrenskMarsh.c" 
#include "$CurrentDir:\\mpmissions\\CHANGEME\\BotMissions\\BotGroupMissionAirport.c" 
#include "$CurrentDir:\\mpmissions\\CHANGEME\\BotMissions\\BotGroupMissionAthena.c" 
#include "$CurrentDir:\\mpmissions\\CHANGEME\\BotMissions\\BotGroupMissionBKL02.c" 
#include "$CurrentDir:\\mpmissions\\CHANGEME\\BotMissions\\BotGroupMissionBoat.c"
#include "$CurrentDir:\\mpmissions\\CHANGEME\\BotMissions\\BotGroupMissionIslandBase.c"
#include "$CurrentDir:\\mpmissions\\CHANGEME\\BotMissions\\BotGroupMissionVorkuta1.c"
#include "$CurrentDir:\\mpmissions\\CHANGEME\\BotMissions\\BotGroupMissionJalovisko.c"
#include "$CurrentDir:\\mpmissions\\CHANGEME\\BotMissions\\BotGroupMissionLumjanskport.c"
#include "$CurrentDir:\\mpmissions\\CHANGEME\\BotMissions\\BotGroupMissionNorinsk.c"
#include "$CurrentDir:\\mpmissions\\CHANGEME\\BotMissions\\BotGroupMissionSawmill.c"
#include "$CurrentDir:\\mpmissions\\CHANGEME\\BotMissions\\BotGroupMissionSebjan.c"
#include "$CurrentDir:\\mpmissions\\CHANGEME\\BotMissions\\BotGroupMissionTown.c"
#include "$CurrentDir:\\mpmissions\\CHANGEME\\BotMissions\\BotGroupMissionSub.c"
#include "$CurrentDir:\\mpmissions\\CHANGEME\\BotMissions\\BotGroupMissionTaraHarbor.c"
#include "$CurrentDir:\\mpmissions\\CHANGEME\\BotMissions\\BotGroupMissionTrainBridge.c"
#include "$CurrentDir:\\mpmissions\\CHANGEME\\BotMissions\\BotGroupMissionVorkuta.c"
#include "$CurrentDir:\\mpmissions\\CHANGEME\\BotMissions\\BotGroupMissionTroick.c"

class initBotMissions
{
	void initBotMissions() {};
	
	void runBotMissions()
	{
		// запуск миссии Тисы--------------------------------------------
		BotGroupMissionFactory2 onMissionFactory2 = new BotGroupMissionFactory2();
		onMissionFactory2.StartMissionAI();	
		//---------------------------------------------------------------
		
		BotGroupMissionBridge onMissionBridge = new BotGroupMissionBridge();
		onMissionBridge.StartMissionAI();	
		
		BotGroupMissionFactory onMissionFactory = new BotGroupMissionFactory();
		onMissionFactory.StartMissionAI();	
		
		BotGroupMissionHospital onMissionHospital = new BotGroupMissionHospital();
		onMissionHospital.StartMissionAI();	
		
		BotGroupMissionBrenskMarsh onMissionBrenskMarsh = new BotGroupMissionBrenskMarsh();
		onMissionBrenskMarsh.StartMissionAI();
		
		BotGroupMissionAirport onMissionAirport = new BotGroupMissionAirport();
		onMissionAirport.StartMissionAI();	
		
		BotGroupMissionAthena onMissionAthena = new BotGroupMissionAthena();
		onMissionAthena.StartMissionAI();	
		
		BotGroupMissionBKL02 onMissionBKL02 = new BotGroupMissionBKL02();
		onMissionBKL02.StartMissionAI();
		
		BotGroupMissionBoat onMissionBoat = new BotGroupMissionBoat();
		onMissionBoat.StartMissionAI();
        
        BotGroupMissionIslandBase onMissionIslandBase = new BotGroupMissionIslandBase();
		onMissionIslandBase.StartMissionAI();
        
        BotGroupMissionJalovisko onMissionJalovisko = new BotGroupMissionJalovisko();
		onMissionJalovisko.StartMissionAI();
        
        BotGroupMissionVorkuta1 onMissionVorkuta1 = new BotGroupMissionVorkuta1();
		onMissionVorkuta1.StartMissionAI();
        
        BotGroupMissionLumjanskport onMissionLumjanskport = new BotGroupMissionLumjanskport();
		onMissionLumjanskport.StartMissionAI();
        
        BotGroupMissionNorinsk onMissionNorinsk = new BotGroupMissionNorinsk();
		onMissionNorinsk.StartMissionAI();
        
        BotGroupMissionSawmill onMissionSawmill = new BotGroupMissionSawmill();
		onMissionSawmill.StartMissionAI();
        
        BotGroupMissionSebjan onMissionSebjan = new BotGroupMissionSebjan();
		onMissionSebjan.StartMissionAI();
        
        BotGroupMissionTown onMissionTown = new BotGroupMissionTown();
		onMissionTown.StartMissionAI();
        
        BotGroupMissionSub onMissionSub = new BotGroupMissionSub();
		onMissionSub.StartMissionAI();
        
        BotGroupMissionTaraHarbor onMissionTaraHarbor = new BotGroupMissionTaraHarbor();
		onMissionTaraHarbor.StartMissionAI();
        
        BotGroupMissionTrainBridge onMissionTrainBridge = new BotGroupMissionTrainBridge();
		onMissionTrainBridge.StartMissionAI();
        
        BotGroupMissionVorkuta onMissionVorkuta = new BotGroupMissionVorkuta();
		onMissionVorkuta.StartMissionAI();
        
        BotGroupMissionTroick onMissionTroick = new BotGroupMissionTroick();
		onMissionTroick.StartMissionAI();
	}
		
}
