#pragma once

#include<string>
#include<iostream>

using namespace std;
class Game
{
public:
	virtual void InitGame() = 0;
	virtual void StartGame() = 0;
	virtual void endGame() = 0;
	virtual void play()
	{
		InitGame();
		StartGame();
		endGame();
	}
};

//class game :public Game
//{
//public:
//	void play()
//	{
//		InitGame();
//		StartGame();
//		endGame();
//	}
//
//};

class CardGame : public Game
{

public:
	void InitGame()
	{
		cout << "CardGame InitGame" << endl;
	}
	void StartGame()
	{
		cout << "CardGame StartGame" << endl;
	}
	void endGame()
	{
		cout << "CardGame endGame" << endl;
	}
};

class ChessGame : public Game
{

public:
	void InitGame()
	{
		cout << "ChessGame InitGame" << endl;
	}
	void StartGame()
	{
		cout << "ChessGame StartGame" << endl;
	}
	void endGame()
	{
		cout << "ChessGame endGame" << endl;
	}
};