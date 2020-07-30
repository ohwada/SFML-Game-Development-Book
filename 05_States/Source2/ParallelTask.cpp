// ParallelTask 
// we have been able to see that a ParallelTask object runs in the background and allows querying some information about the task's progress. 
// To remain as simple as possible explaining the concept of a task executed in a parallel thread, we decided to implement the sample class as a dummy operation that does not do any actual loading, but rather just waits ten seconds for a timer to expire and finalize the task. 

// https://github.com/SFML/SFML-Game-Development-Book/blob/master/05_States/Source/ParallelTask.cpp

#include <Book/ParallelTask.hpp>


ParallelTask::ParallelTask()
: mThread(&ParallelTask::runTask, this)
, mFinished(false)
{
}

void ParallelTask::execute()
{
	mFinished = false;
	mElapsedTime.restart();
	mThread.launch();
}

bool ParallelTask::isFinished()
{
	sf::Lock lock(mMutex);
	return mFinished;
}

float ParallelTask::getCompletion()
{
	sf::Lock lock(mMutex);

	// 100% at 10 seconds of elapsed time
	return mElapsedTime.getElapsedTime().asSeconds() / 10.f;
}

void ParallelTask::runTask()
{
	// Dummy task - stall 10 seconds
	bool ended = false;
	while (!ended)
	{
		sf::Lock lock(mMutex); // Protect the clock 
		if (mElapsedTime.getElapsedTime().asSeconds() >= 10.f)
			ended = true;
	}

	{ // mFinished may be accessed from multiple threads, protect it
		sf::Lock lock(mMutex);
		mFinished = true;
	}	
}