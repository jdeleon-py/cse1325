#include "puzzle.h"
#include "solver.h"

#include <iostream>
#include <fstream>
#include <vector>

#include <algorithm>  // std::sort

#include <thread>
#include <mutex>

/*
class Bobbin
{
public:
	void solve_puzzle()
	{
		for(std::string word : puzzle)
		{
			_m.lock();
			// Find each word in the current puzzle
			// Instance a Solver, and use it to solve for the word
			Solver solver{puzzle};
			Solution s = solver.solve(word);
			solutions.push_back(s);
			_m.unlock();
		}
	}

	Puzzle puzzle;
	std::vector<Solution> solutions;
private:
	std::mutex _m;
};
*/

std::mutex m;
void solve_puzzle(Puzzle puzzle, std::string word, std::vector<Solution> solutions)
{
	m.lock();
	Solver solver{puzzle};
	Solution s = solver.solve(word);
	solutions.push_back(s);
	m.unlock();
}

int main(int argc, char* argv[])
{
	static const int NUM_THREADS = 4;
	std::thread t[NUM_THREADS];
	//Bobbin bobbin;

	// Load the puzzles
	std::vector<Puzzle> puzzles;
	for(int i = 1; i < argc; ++i)
	{
		try
		{
			std::string filename = std::string{argv[i]};
			std::ifstream ifs{filename};
			puzzles.push_back(Puzzle{filename, ifs});
		}
		catch(std::exception& e)
		{
			std::cerr << "Unable to open " << argv[i] << ": " << e.what() << std::endl;
		}
	}

	// Exit if one or more puzzles failed to load
	if((argc-1) != puzzles.size()) exit(-1);

	// ----- All data loaded -----

	// Capture the solutions in a vector
	std::vector<Solution> solutions;

	for(Puzzle& puzzle: puzzles)
	{
		for(std::string word : puzzle)
		{
			//for(int i = 0; i < NUM_THREADS; ++i) t[i] = std::thread{[&bobbin] {bobbin.solve_puzzle();}};
			for(int i = 0; i < NUM_THREADS; ++i) t[i] = std::thread(solve_puzzle, puzzle, word, solutions);
			for(int i = 0; i < NUM_THREADS; ++i) t[i].join();
		}
	}
	std::sort(solutions.begin(), solutions.end());
	for(Solution& s : solutions) std::cout << s << std::endl;
}
