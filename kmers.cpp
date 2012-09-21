#include <iostream>
#include <map>
#include <cmath>
#include <stdlib.h>

using namespace std;

int main (int argc, char** argv) {

    if (argc != 3) {
	cerr << "usage: " << argv[0] << " [kmermin] [kmermax]" << endl
	     << "Generate kmer frequency statistics for all kmers in stdin" << endl
	     << "for kmers between kmermin and kmermax size." << endl;
	return 1;
    }

    int kmermin = atoi(argv[1]);
    int kmermax = atoi(argv[2]);

    char c;
    string buf;

    long long totalchrs = 0;
    map<string, long long> kmers;
    
    while (cin.good()) {
	cin.get(c);
	if (cin.good()) {
	    ++totalchrs;
	    if ((int) buf.size() == kmermax) {
		buf = buf.substr(1);
	    }
	    buf.append(1, c);
	    for (int i = kmermin; i <= (int) buf.size(); ++i) {
		string kmer = buf.substr(buf.size() - i, i);
		++kmers[kmer];
	    }
	}
    }

    cout << "kmer\tcount\tfreq\tlfreq" << endl;

    for (map<string, long long>::iterator k = kmers.begin(); k != kmers.end(); ++k) {
	const string& kmer = k->first;
	long long count = k->second;
	long double freq = (long double) count / ((long double) totalchrs - (kmer.size() - 1));
	cout << kmer << "\t" << count << "\t" << freq << "\t" << log10(freq) << endl;
    }

    return 0;

}
