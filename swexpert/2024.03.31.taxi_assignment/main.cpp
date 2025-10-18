typedef long long ll;
const int N=1'000'000;
const ll PENALTY=1'000'000'000'000LL;
//driver: 51<=M<=100
//passenger: 5001<=K<=10000
uint seed = 5U;
uint pseudo_rand() {
	seed = seed * 214013U + 2531011U;
	return (seed<<16) ^ seed;
}
struct Coordinates{
	int x,y;
};
struct Passenger{
	Coordinates departure;
	Coordinates arrival;
};
Coordinates mDriver[100];
Passenger mPassenger[10000];
ll TC_SCORE;
void driver_assign(int driverIdx, int passengerSize, int *passengerIdxList) {
	int &sx = mDriver[driverIdx].x;
	int &sy = mDriver[dirverIdx].y;

	ll dist = 0LL;
	for(int i=0; i<passengerSize; i++) {
		if(alreadyMoved[passengerIdxList[i]]) {
			TC_SCORE = PENALTY;
			return;
		}
		alreadyMoved[passengerIdxList[i]] = true;
		dist += ABS(mPassenger[passengerIdxList[i]].departure.x - sx) + ABS(mPassenger[passengerIdxList[i]].departure.y - sy);
		dist += ABS(mPassenger[passengerIdxList[i]].arrival.x - mPassenger[passengerIdxList[i]].departure.x);
		dist += ABS(mPassenger[passengerIdxList[i]].arrival.y - mPassenger[passengerIdxList[i]].departure.y);
		sx = mPassenger[passengerIdxList[i]].arrival.x;
		sy = mPassenger[passengerIdxList[i]].arrival.y;
	}
	TC_SCORE = MAX(TC_SCORE, dist);
}
int main() {
	int tc = 5;
	ll SCORE = 0LL;
	while(tc--) {
		int N = 1000000; //map size = N*N
		int M = pseudo_rand()%50+51; //the number of taxi drivers
		int K = pseudo_rand()%5000+5001; //the number of passengers
		TC_SCORE = 0LL;

		for(int i=0; i<K; i++) {
			alreadyMoved[i] = false;
		}

		for(int i=0; i<M; i++) {
			mDriver[i] = {pseudo_rand()%N, pseudo_rand()%N};
		}
		for(int i=0; i<K; i++) {
			mPassenger[i].departure = {pseudo_rand()%N, pseudo_rand()%N};
			mPassenger[i].arrival = {pseudo_rand()%N, pseudo_rand()%N};
		}

		taxi_assignment(N,M,mDriver,K,mPassenger);
		if(TC_SCORE == PENALTY) {
			break;
		}
		SCORE += TC_SCORE;
	}

	printf("SCORE: %lld\n", SCORE);
	return 0;
}
