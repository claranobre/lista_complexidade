#include <ctime>
#include <iostream>

	using std::cout;
	using std::endl;

	#define NTrials 10 // Number of trials
	void randomize(){
	srand((int) time (NULL));
	}

	int randInt(int low, int high){
		int k;
		double d;
	}

	d = (double) rand() / ((double) RAND_MAX + 1);
	k = (int) (d *(high - low + 1));
		return (low + k);
	}


int main(){

	cout << " >> On this computer , RAND_MAX = " << RAND_MAX << endl ;
	cout << " >> " << NTrials << " calls to rand ( same seed ):\n " ;

		for (int i = 0; i < NTrials ; i ++)
		cout << rand () << endl;
		randomize ();

		cout << " \n > > " << NTrials << " calls to rand ( time - based seed ):\n ";
		
		for (int i = 0; i < NTrials ; i ++ )
		cout << rand () << endl ;
		cout << " \n > > " << NTrials << " calls to rand ( range [1 -10]):\n ";
			
			for(int i = 0; i < NTrials ; i ++ )
			cout << randInt (1 ,10) << endl ;
			
			return ( EXIT_SUCCESS );
}