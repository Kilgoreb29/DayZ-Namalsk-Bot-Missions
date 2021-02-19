


Make sure you change this "#include "$CurrentDir:\\mpmissions\\CHANGEME\\BotMissions\\initBotMissions.c" to your mission. // Do not copy.. 

\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


    Add this to your init like so, then change the CHANGEME to your mission.
    
    

#include "$CurrentDir:\\mpmissions\\CHANGEME\\BotMissions\\initBotMissions.c"

void main()
{
	// Инициализация миссий с ботами ------------------------------
	initBotMissions m_BotMissions = new initBotMissions();	
	m_BotMissions.runBotMissions();
	//-------------------------------------------------------------
       
    

    
    
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
    
    
    Make sure to change CHANGEME initBotMissions.c's also.
    
#include "$CurrentDir:\\mpmissions\\CHANGEME\\BotMissions\\BotGroupMissionFactory2.c" 
#include "$CurrentDir:\\mpmissions\\CHANGEME\\BotMissions\\BotGroupMissionBridge.c" 



