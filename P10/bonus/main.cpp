#include "puzzle.h"
#include "solver.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

#include <algorithm>  // std::sort

#include <thread>
#include <mutex>

int main(int argc, char* argv[])
{
	std::ostringstream oss_usage;
	oss_usage << "usage: " << argv[0] << " threads puzzle [puzzle]..\n";
	std::string usage = oss_usage.str();

	if(argc < 3)
	{
		std::cerr << usage;
		exit(-1);
	}

	// Extract parameter 1
	std::string p1 = std::string(argv[1]);

	// Check for help request
	if(p1 == "-h" || p1 == "--help")
	{
		std::cerr << usage;
		exit(0);
	}

	//Read number of threads
	int NUM_THREADS;
	try
	{
		NUM_THREADS = std::stoi(p1);
	}
	catch(std::exception& e)
	{
		std::cerr << "Unable to read number of threads from "
			  << p1 << ": " << e.what() << '\n'
			  << usage;
		exit(-2);
	}

	// Load the puzzles
	std::vector<Puzzle> puzzles;
	for(int i = 2; i < argc; ++i)
	{
		try
		{
			std::string filename = std::string{argv[i]};
			std::ifstream ifs{filename};
			puzzles.push_back(Puzzle{filename, ifs});
		}
		catch(std::exception& e)
		{
			std::cerr << "Unable to open " << argv[1] << ": "
			  	  << e.what() << std::endl;
		}
	}

	// Exit if one or more puzzles failed to load
	if((argc - 2) != puzzles.size()) exit(-3);

	// --- ALL DATA LOADED ---

	std::vector<Solution> solutions;

	std::vector<std::thread*> threads;
	std::mutex m;

	int next_puzzle = 0;

	for(int i = 0; i < NUM_THREADS; ++i)
	{
		threads.push_back(new std::thread{[&] {
			while(true)
			{
				m.lock();
				int p = next_puzzle++;
				m.unlock();
				if(p >= puzzles.size()) break;
				Puzzle& puzzle = puzzles.at(p);
				Solver solver{puzzle};
				for(std::string word : puzzle)
				{
					Solution s = solver.solve(word);
					m.lock();
					solutions.push_back(s);
					m.unlock();
				}
			}
		}});
	}

	for(std::thread* t : threads) t -> join();

	std::sort(solutions.begin(), solutions.end());
	for(Solution& s : solutions) std::cout << s << std::endl;
}

