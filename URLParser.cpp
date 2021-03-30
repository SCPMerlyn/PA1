//this program will parse a URL inputted
//another commen
//a testing commentt
#include <iostream>
#include <iomanip>

using namespace std;

void displayVersion();
int main() {
    string url;
    string results[5];
    int protocolLength = 0;
    int period1Loc = -1, period2Loc = -1, colonLoc =-1,slashLoc = -1, period3Loc = -1, quesLoc = -1, equalLoc = -1;

    displayVersion();

    cout << "Enter URL to parse it" << endl;
    cin >> url;

    //check protocol
    for(int i = 0; i < url.length(); i++){
        if (char(url[i]) == ':' ){
            protocolLength = i;
            break;
        }
    }

        if(protocolLength == 5) {
            if(url.substr(0, 5).compare("https") == 0 ) {
                results[0] = "Protocol:    " +  url.substr(0, 5);
            } else {
                results[0] = "0Protocol:     " +  url.substr(0, protocolLength) + " is not a valid protocol.";
            }

        } else if (protocolLength == 4) {
            if (url.substr(0, 4).compare("http") == 0 || url.substr(0, 4).compare("ftps") == 0) {
                results[0] = "Protocol:    " +  url.substr(0, 4);
            } else {
                results[0] = "0Protocol:     " +  url.substr(0, protocolLength) + " is not a valid protocol.";
            }
        } else if (protocolLength ==3 ) {
            if(url.substr(0, 3).compare("ftp") == 0) {
                results[0] =  "Protocol:    " +  url.substr(0, 3);
            } else {
                results[0] = "0Protocol:       " +  url.substr(0, protocolLength) + " is not a valid protocol.";
            }

        } else {
            results[0] = "0Protocol:     " +  url.substr(0, protocolLength) + " is not a valid protocol.";
        }

    //Locate the punctuations
    for(int i = protocolLength; i < url.length(); i++){
        if (char(url[i]) == '.' ){
            period1Loc = i;
            break;
        }
    }

    if(period1Loc !=-1) {
        for(int i = period1Loc+1; i < url.length(); i++){
            if (char(url[i]) == '.' ){
                period2Loc = i;
                break;
            }
        }
    }

    if(period2Loc !=-1) {
        for(int i = period2Loc+1; i < url.length(); i++){
            if (char(url[i]) == ':' ){
                colonLoc = i;
                break;
            }
        }

        for(int i = period2Loc+1; i < url.length(); i++){
            if (char(url[i]) == '/' ){
                slashLoc = i;
                break;
            }
        }
     }

     if(slashLoc!= -1) {
        for(int i = slashLoc+1; i < url.length(); i++){
            if (char(url[i]) == '.' ){
                period3Loc = i;
                break;
            }
        }
     }

     if(period3Loc !=-1) {
        for(int i = period3Loc+1; i < url.length(); i++){
            if (char(url[i]) == '?' ){
                quesLoc = i;
                break;
            }
        }

        for(int i = period3Loc+1; i < url.length(); i++){
            if (char(url[i]) == '=' ){
                equalLoc = i;
                break;
            }
        }
     }

    if(period1Loc == -1 || period2Loc == -1 || slashLoc == -1 ||  period3Loc ==  -1 || url.substr(protocolLength, 3) != "://") {
        results[0] = "+URL format is incorrect";
    } else {
        //check the domain
        if(colonLoc != -1){
                if (url.substr(period2Loc+1, colonLoc - period2Loc-1) == "com" || url.substr(period2Loc+1, colonLoc - period2Loc-1) == "net" || url.substr(period2Loc+1, colonLoc - period2Loc-1) == "edu" || url.substr(period2Loc+1, colonLoc - period2Loc-1) == "biz" || url.substr(period2Loc+1, colonLoc - period2Loc-1) == "gov") {
                    results[1] = "Domain:      " +  url.substr(protocolLength+3, colonLoc - protocolLength-3);

                } else {
                    results[1] = "0Domain:       " +  url.substr(period2Loc+1, colonLoc - period2Loc-1) + " is an invalid domain name.";
                }
        } else {
            if (url.substr(period2Loc+1, slashLoc - period2Loc-1) == "com" || url.substr(period2Loc+1, slashLoc - period2Loc-1) == "net" || url.substr(period2Loc+1, slashLoc - period2Loc-1) == "edu" || url.substr(period2Loc+1, slashLoc - period2Loc-1) == "biz" || url.substr(period2Loc+1, slashLoc - period2Loc-1) == "gov") {
                results[1] = "Domain:      " +  url.substr(protocolLength+3, slashLoc - protocolLength-3);

            } else {
                results[1] = "0Domain:         " +  url.substr(period2Loc+1, slashLoc - period2Loc-1) + " is an invalid domain name.";
            }
        }

        //check the optional port
        if(colonLoc != -1){
                if (stoi(url.substr(colonLoc+1, slashLoc - colonLoc-1)) >= 1 && stoi(url.substr(colonLoc+1, slashLoc - colonLoc-1)) <= 65535 ) {
                    results[2] = "Port:        " +  url.substr(colonLoc+1, slashLoc - colonLoc-1);

                } else {
                    results[2] = "0Port:         port number must be between 1 and 65535.";
                }
        } else {
            results[2] = "-" ;
        }

        //check the file path
        if(quesLoc != -1){
                 if (url.substr(period3Loc+1, quesLoc - period3Loc-1) == "html" || url.substr(period3Loc+1, quesLoc - period3Loc-1) == "htm" ) {
                    results[3] = "File Path:   " +  url.substr(slashLoc, quesLoc - slashLoc);

                } else {
                    results[3] = "0File Path:    " +  url.substr(slashLoc, quesLoc - slashLoc) + " is an invalid path name.";
                }
        } else {
            if (url.substr(period3Loc+1, url.length()-1) == "html" || url.substr(period3Loc+1, url.length()-1) == "htm" ) {
                results[3] = "File Path:   " +  url.substr(slashLoc, url.length()-1);
            } else {
                results[3] = "0File Path:    " +  url.substr(slashLoc, url.length()-1) + " is an invalid path name.";
            }
        }

        //check for parameter
        if (equalLoc != -1 && quesLoc != -1){
            results[4] = "Parameters:  " +  url.substr(quesLoc+1, url.length()-1);

        } else  if (equalLoc == -1 && quesLoc != -1){
            results[4] = "0Parameters:   " +  url.substr(quesLoc+1, url.length()-1) + " is an invalid parameter.";
        } else {
            results[4] = "-";
        }
    }

    //print out the results
      if(results[0].at(0) == '+') {
        cout << results[0].substr(1, results[0].length()-1) << endl;
        cout << "Format should be: \nprotocol://<x>.<y>.<z>:port/path?variable=variable" << endl << endl;
        cout << "Valid Protocol options:" << setw(34) << "http, https, ftp, ftps" << endl;
        cout << "Valid Domain options for z value:  com, net, edu, biz, gov" << endl;
        cout << "Valid Port values*:                number between 1 to 65535" << endl;
        cout << "Valid File Path:                   must start with \' / \' and end with either .html ot .htm" << endl;
        cout << "Valid Parameters*:                 must start with \'?\' and have a variable before and after the \'=\' " << endl;
        cout << "* symbol denotes optional components" << endl;
     } else if (results[0].at(0) == '0' || results[1].at(0) == '0' || results[2].at(0) == '0' || results[3].at(0) == '0' || results[4].at(0) == '0') {
        cout << "Invalid URL with following erroneous components:" << endl;
        for(int j = 0; j < 5; j++ ) {
             if (results[j].at(0) == '0') {
                cout << results[j].substr(1, results[j].length()-1) << endl;
             }
        }

    } else {
        cout << results[0] << endl;
        cout << results[1] << endl;
        if(results[2].at(0) != '-') {
            cout << results[2] << endl;
        }
        cout << results[3] << endl;
        if(results[4].at(0) != '-') {
            cout << results[4] << endl;
        }
    }


    return 0;
}

