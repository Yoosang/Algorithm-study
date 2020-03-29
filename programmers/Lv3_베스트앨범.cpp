#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compareGenre(pair<string, int> a, pair<string, int> b) {
	return a.second > b.second;
}

bool comparePlays(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first > b.first;
}

vector<pair<string, int>> genreCnt(vector<string> genres, vector<int> plays) {
	vector<pair<string, int>> ret;
	bool flag;
	for (unsigned j = 0; j < genres.size(); j++ ) {
		string genre = genres[j];
		flag = false;
		for (unsigned i = 0; i < ret.size(); i++) {
			if (ret[i].first == genre) {
				ret[i].second += plays[j];
				flag = true;
				break;
			}
		}
		if (!flag) {
			ret.push_back({ genre, plays[j] });
		}
	}
	sort(ret.begin(), ret.end(), compareGenre);
	return ret;
}

vector<pair<int, int>> playsCnt(string cur_genre, vector<string> genres, vector<int> plays) {
	vector<pair<int, int>> ret;
	for (unsigned i = 0; i < genres.size(); i++) {
		if (cur_genre == genres[i]) {
			ret.push_back({ plays[i], i });
		}
	}
	sort(ret.begin(), ret.end(), comparePlays);
	return ret;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	vector<pair<string, int>> genre_seq;	//pair: genre name, the number of play in genre
	vector<pair<int, int>> plays_seq;		//pair: the number of play, song number

	genre_seq = genreCnt(genres, plays);

	for (unsigned i = 0; i < genre_seq.size(); i++) {
		plays_seq = playsCnt(genre_seq[i].first, genres, plays);
		for (unsigned j = 0; j < plays_seq.size(); j++) {
			if (i == 2) {
				break;
			}
			answer.push_back(plays_seq[i].second);
		}
	}
	return answer;
}
