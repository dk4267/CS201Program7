//Debbie Kirchner
//dkkbd@mail.umkc.edu
//CS201 Program 7
//Due 5/10/19

#include <fstream>
#include <string>
#include <map>
#include <iostream>
#include <iomanip>
using namespace std;

int main() {

	//Initialize 2 maps: one for the number of reviews for each restaurant, one for the total of the reviews.
	map<string, int> numReviews;
	map<string, double> reviews;
	ifstream in;
	int totalReviews;
	string restaurant;
	int currReview;

	in.open("ratings.txt");

	//Input the total number of reviews in the file
	in >> totalReviews;
	in.ignore();

	//For each review, input the restaurant and the rating
	for (int i = 0; i < totalReviews; i++) {
		getline(in, restaurant);
		in >> currReview;

		//If the restaurant is not already in the first map, add its info to both maps (since it would be in neither)
		//Initialize the review count to 1 in the first map, and the rating in the second map
		if (numReviews.count(restaurant) == 0) {
			numReviews.emplace(restaurant, 1);
			reviews.emplace(restaurant, currReview);
		}

		//If the restaurant is already in the first map, adjust its info
		//Increment the review count by 1 in the first map, and add the rating to the total in the second map
		else {
			numReviews.at(restaurant) += 1;
			reviews.at(restaurant) += currReview;
		}
		//The getline() function will be called after this, so ignore() will ignore the \n character at the end of the line
		in.ignore();
	}
	in.close();
	
	//Declare an iterator and use it to iterate through the first map
	for (auto it = numReviews.begin(); it != numReviews.end(); ++it) {

		//Access the data in the elements of the first map by it->first and it-> second
		string currRestaurant = it->first;
		int currNum = it->second;

		//Use this info to get the total of the reviews from the second map
		double currTotal = reviews.at(currRestaurant);

		//Calculate the average reviews from the total of the reviews and the number of reviews
		double avgReview = currTotal / currNum;

		//Output the results in a nice way
		cout << currRestaurant;
		cout << setw(20 - currRestaurant.size()) << left << ":";
		cout << currNum;
		cout << setw(12) << left <<" reviewers.";
		cout << "Average of " << avgReview << "/5" << endl;
	}

	system("pause");
	return 0;
}