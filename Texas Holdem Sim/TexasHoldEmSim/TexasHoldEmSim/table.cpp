// table.cpp

#include "table.h"

Table::Table(double m, int num): smallBlind(10), bigBlind(15)
{
	numPlayers=num;
	Player player1(m,preFlopOdds);
	Player player2(m,preFlopOdds);
	Player player3(m,preFlopOdds);
	Player player4(m,preFlopOdds);
	Player player5(m,preFlopOdds);
	Player player6(m,preFlopOdds);
	Player player7(m,preFlopOdds);
	Player player8(m,preFlopOdds);
	Player player9(m,preFlopOdds);
	Player player10(m,preFlopOdds);
	tempList10Players.push_back(player1);
	tempList10Players.push_back(player2);
	tempList10Players.push_back(player3);
	tempList10Players.push_back(player4);
	tempList10Players.push_back(player5);
	tempList10Players.push_back(player6);
	tempList10Players.push_back(player7);
	tempList10Players.push_back(player8);
	tempList10Players.push_back(player9);
	tempList10Players.push_back(player10);
	for(int i; i!=numPlayers; i++)
	{
		playerList.push_back(tempList10Players[i]);
	}
}

void Table::Init()
{
	InitPositions();
	NewRound();	
}

void Table::InitPositions()
{	
	//sets iter to beginning of vector
	iter = playerList.begin();
	int i = 0;
	
	//positions setup: 0->Dealer,1->small blinds,2->big blinds,3->early,4->middle,5->late
	
	//cases for each number of players
	switch(numPlayers)
	{
		//if 2 players, 1st player is dealer and small blind, 2nd player is Early
	    case 2:
			for(;iter != playerList.end(); iter++)
			{			
				
				iter->SetPos(i);
				
				i+=3;
			}
	        break;
	    
	    case 3:
			for(;iter != playerList.end(); iter++)
			{			
				
				iter->SetPos(i);
				
				i++;
			}
	        break;
	        
	    case 4:
		    for(;iter != playerList.end(); iter++)
			{			
				
				iter->SetPos(i);
				
				i++;
			}
	        break;
	    
	    case 5:
			for(;iter != playerList.end(); iter++)
			{			
				
				iter->SetPos(i);
				
				i++;
			}
	        break;
	        
	    case 6:
			for(;iter != playerList.end(); iter++)
			{			
				
				iter->SetPos(i);
				
				i++;
			}
	        break;
	    
	    case 7:
			for(;iter != playerList.end(); iter++)
			{			
				
				iter->SetPos(i);
				
				i++;
			}
	        break;	        	        
	
	    case 8:
			for(;iter != playerList.end(); iter++)
			{			
				
				iter->SetPos(i);
				
				i++;
			}
	        break;
	    
	    case 9:
			for(;iter != playerList.end(); iter++)
			{			
				
				iter->SetPos(i);
				
				i++;
			}
			break;

		case 10:
			for(;iter != playerList.end(); iter++)
			{			
				
				iter->SetPos(i);
				
				i++;
			}
			break;

	} 
} // InitPositions()

void Table::OddsTable(int numPlayers)
{
	ifstream file;
	file.open("odds.txt");
	string hole, tmp;
	double weight;
	string a, b;

	preFlopOdds.clear();

	for (int i = 0; i < 169; i++)
	{
		file >> hole;
		file >> weight;
		weight = weight / 31.5;

		a = hole[0];		
		b = hole[1];
		
		cout << "\nhole[0]: " << a << "\nhole[1]: " << b;

		if( hole.length() == 2 )
		{
			tmp = a + 'h' + b + 'c';
			preFlopOdds[tmp] = weight;
			cout << "\npreFlopOdds[ " << tmp << "] = " << weight << "\n";
			
			tmp = a + 'h' + b + 's';
			preFlopOdds[tmp] = weight;
			cout << "\npreFlopOdds[ " << tmp << "] = " << weight << "\n";
			
			tmp = a + 'h' + b + 'd';
			preFlopOdds[tmp] = weight;    
            cout << "\npreFlopOdds[ " << tmp << "] = " << weight << "\n";
			
			tmp = a + 'c' + b + 'h';
			preFlopOdds[tmp] = weight;
            cout << "\npreFlopOdds[ " << tmp << "] = " << weight << "\n";			
			
			tmp = a + 'c' + b + 's';
			preFlopOdds[tmp] = weight;
            cout << "\npreFlopOdds[ " << tmp << "] = " << weight << "\n";			
			
			tmp = a + 'c' + b + 'd';
			preFlopOdds[tmp] = weight;
            cout << "\npreFlopOdds[ " << tmp << "] = " << weight << "\n";

			tmp = a + 's' + b + 'h';
			preFlopOdds[tmp] = weight;
            cout << "\npreFlopOdds[ " << tmp << "] = " << weight << "\n";
			
			tmp = a + 's' + b + 'c';
			preFlopOdds[tmp] = weight;
            cout << "\npreFlopOdds[ " << tmp << "] = " << weight << "\n";
			
			tmp = a + 's' + b + 'd';
			preFlopOdds[tmp] = weight;
            cout << "\npreFlopOdds[ " << tmp << "] = " << weight << "\n";

			tmp = a + 'd' + b + 'h';
			preFlopOdds[tmp] = weight;
            cout << "\npreFlopOdds[ " << tmp << "] = " << weight << "\n";
			
			tmp = a + 'd' + b + 'c';
			preFlopOdds[tmp] = weight;
            cout << "\npreFlopOdds[ " << tmp << "] = " << weight << "\n";
			
			tmp = a + 'd' + b + 's';
			preFlopOdds[tmp] = weight;
            cout << "\npreFlopOdds[ " << tmp << "] = " << weight << "\n";
		}
		else
		{ // suited cards
			tmp = a + 'h' + b + 'h';
			preFlopOdds[tmp] = weight;
            cout << "\npreFlopOdds[ " << tmp << "] = " << weight << "\n";

			tmp = a + 'c' + b + 'c';
			preFlopOdds[tmp] = weight;
			cout << "\npreFlopOdds[ " << tmp << "] = " << weight << "\n";

			tmp = a + 's' + b + 's';
			preFlopOdds[tmp] = weight;
            cout << "\npreFlopOdds[ " << tmp << "] = " << weight << "\n";

			tmp = a + 'd' + b + 'd';
			preFlopOdds[tmp] = weight;
            cout << "\npreFlopOdds[ " << tmp << "] = " << weight << "\n";			
		}
	}
	
	file.close();

} // preFlopOddsTable()

void Table::NewRound()
{
	int p = 0;

	//reset pot and flags
    pot = 0.0;
	limitAction = false;
	
	//checks to see if its time to raise the blinds and then raises them if it is
	//bool raise = CheckTime();
	//if(raise == true)
	//{
	//	smallBlind += 5.0;
	//	bigBlind += 10.0;
	//}

	//recalculates preFlopOdds table based on new number of players
	OddsTable(numPlayers);
	
	//creates and shuffles deck
	deck1.ShuffleCard();

	//determines where the dealer is to move positions
	DetDealer();
	
	//moves position of dealer
	iter = playerList.begin() + (dealerPosition + 1);
	for(;iter != playerList.end();iter++)
	{
		iter->SetPos(p);
		p++;
	}
	iter = playerList.begin();
	for(;iter != (playerList.begin() + (dealerPosition + 1));iter++)
	{
		iter->SetPos(p);
		p++;
	}

	//update dealer
	DetDealer();
	
	//starts game
	NextAction();
}

void Table::DealCards(int type)
{
	
	int g = 1;

	if(type == HOLECARDS)
	{	
		while(g < 3)
		{
			iter = playerList.begin() + (dealerPosition + 1);
			for(; iter != playerList.end(); iter++)
			{
				card c = deck1.deck.back();
				iter->AddCard(c,HOLECARDS);
				deck1.deck.pop_back();
			}
			iter = playerList.begin();
			for(; iter != (playerList.begin() + (dealerPosition + 1)); iter++)
			{
				card c = deck1.deck.back();
				iter->AddCard(c,HOLECARDS);
				deck1.deck.pop_back();
			}
			g++;
		}
	}
	else if(type == FLOP)
	{
		g = 1;
		while(g < 4)
		{
			for(;iter != playerList.end();iter++)
			{
				card c = deck1.deck.back();
				iter->AddCard(c,FLOP);
			}
			iter = playerList.begin();
			for(;iter != playerList.begin() + (dealerPosition + 1);iter++)
			{
				card c = deck1.deck.back();
				iter->AddCard(c,FLOP);
			}
			deck1.deck.pop_back();
			g++;
		}

	}
	else if(type == TURN)
	{
		for(;iter != playerList.end();iter++)
		{
			card c = deck1.deck.back();
			iter->AddCard(c,TURN);
		}
		iter = playerList.begin();
		for(;iter != playerList.begin() + (dealerPosition + 1);iter++)
		{
			card c = deck1.deck.back();
			iter->AddCard(c,TURN);
		}
		deck1.deck.pop_back();
	}
	else if(type == RIVER)
	{
		for(;iter != playerList.end();iter++)
		{
			card c = deck1.deck.back();
			iter->AddCard(c,RIVER);
		}
		iter = playerList.begin();
		for(;iter != playerList.begin() + (dealerPosition + 1);iter++)
		{
			card c = deck1.deck.back();
			iter->AddCard(c,RIVER);
		}
		deck1.deck.pop_back();
	}

} // DealCard

void Table::NextAction()
{     
	//deal holecards, start actions based on holecards only
	DealCards(HOLECARDS);
	Eligible();
	iter = playerList.begin() + (dealerPosition + 1);
	for(;iter != playerList.end();iter++)
	{	
		if(iter->DidFold())
			continue; //skip them, they don't get an action			
		else
			pot += iter->Action(limitAction);
	}
	iter = playerList.begin();
	for(;iter != playerList.begin() + (dealerPosition +1);iter++)
	{		
		if(iter->DidFold())
			continue; //skip them, they don't get an action			
		else
			pot += iter->Action(limitAction);
	}
	
	//deal flop and than whoever is left continues to make actions
	DealCards(FLOP);
	Eligible();
	iter = playerList.begin() + (dealerPosition + 1);
	for(;iter != playerList.end();iter++)
	{	
		if(iter->DidFold())
			continue; //skip them, they don't get an action			
		else
			pot += iter->Action(limitAction);
	}
	iter = playerList.begin();
	for(;iter != playerList.begin() + (dealerPosition +1);iter++)
	{		
		if(iter->DidFold())
			continue; //skip them, they don't get an action			
		else
			pot += iter->Action(limitAction);
	}
	
	//deal turn and then whoever is left continues
	DealCards(TURN);
	Eligible();
	iter = playerList.begin() + (dealerPosition + 1);
	for(;iter != playerList.end();iter++)
	{	
		if(iter->DidFold())
			continue; //skip them, they don't get an action			
		else
			pot += iter->Action(limitAction);
	}
	iter = playerList.begin();
	for(;iter != playerList.begin() + (dealerPosition +1);iter++)
	{		
		if(iter->DidFold())
			continue; //skip them, they don't get an action			
		else
			pot += iter->Action(limitAction);
	}

	//deal river and whoever is left continues
	DealCards(RIVER);
	Eligible();
	iter = playerList.begin() + (dealerPosition + 1);
	for(;iter != playerList.end();iter++)
	{	
		if(iter->DidFold())
			continue; //skip them, they don't get an action			
		else
			pot += iter->Action(limitAction);
	}
	iter = playerList.begin();
	for(;iter != playerList.begin() + (dealerPosition +1);iter++)
	{		
		if(iter->DidFold())
			continue; //skip them, they don't get an action			
		else
			pot += iter->Action(limitAction);
	}

	
} 

void Table::DetDealer()
{
	//determines current position of dealer so we can move positions of all players
	iter = playerList.begin();
	int i = 0;
	for(;iter != playerList.end();iter++)
	{		
		int currPos = iter->GetPos();
		if (currPos == 0)
		{
		    dealerPosition = i;
		}
		i++;
	}
} // DetDealer()

void Table::DeclareWinner(int winner) 
{  
	//set iter to element containing the winner
	iter = playerList.begin() + winner;

	//gives the winner the money in the pot
	iter->AddMoney(pot);
	
	//starts the next round
	NewRound();
}

void Table::Eligible()
{
	iter = playerList.begin() + (dealerPosition + 1);
	for(;iter != playerList.end();iter++)
	{		
		if(iter->DidBust())
			playerList.erase(iter); //if they are busted erase them from the list of players (they can't play again this game)
		else if(iter->DidAllIn())
			limitAction = true; //if someone goes all in, players can't raise
	}
	iter = playerList.begin();
	for(;iter != playerList.begin() + (dealerPosition +1);iter++)
	{		
		if(iter->DidBust())
			playerList.erase(iter);
		else if(iter->DidAllIn())
			limitAction = true;
	}
}

bool CheckTime()
{
	return false;

}



