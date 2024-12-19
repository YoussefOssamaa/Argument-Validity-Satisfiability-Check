#include<iostream>
#include<vector>
#include<math.h>


using namespace std ;

class VarStruct{
private:

public:
char name ;
vector <int> truth_vector ;

VarStruct(){}

VarStruct(char varName ,vector <int> truth_vec ){
this ->name = varName ;
this ->truth_vector = truth_vec ;
}




};


class Stack {
    private:
    vector <char> v1 ;

    public:
    Stack(){}

    void push(char c){
    v1.push_back(c);
    }

     char top(){
    return v1.back() ;
    }

    char pop(){

    char t = this->top() ;
    v1.pop_back();
    return t ;
    }
};

int main(){

string str1;
string str2;
string mainStr;

vector <char> mainChar ;
vector <int> statement1_result ;
vector <int> statement2_result ;


bool repeated ;
VarStruct var1 ;
VarStruct var2 ;
VarStruct var3 ;



cout<<"Enter first statement: ";
cin>>str1 ;
cout<<"Enter second statement: ";
cin>>str2 ;
mainStr = str1 + str2 ;


for (char element : mainStr){
    repeated = 0 ;
    if( (element >= 65 && element <=90) || (element >= 97 && element <=122) ) ///check for characters from a->z or from A->Z
        {

        for (int i=0 ; i < (int) mainChar.size()-1 ; i++){
            if (element == mainChar[i]){
                repeated = 1 ;
                break ;
            }
        }
        if (!repeated){
        mainChar.push_back(element) ;
        }


    }
}

bool boo = 1 ;
int k=3;  ///number of variables

vector <int> v3 ;
boo = 1 ;
for (int i = 0  ; i < 2 ; i++ ){
 for (int l=0 ; l< pow(2,k)/2 ; l++  ){
        v3.push_back(boo) ;
    }
    boo = ! boo ;
    }

vector <int> v2 ;
 boo = 1 ;

for (int i = 0  ; i < 4 ; i++ ){
 for (int l = 0 ; l < pow(2,k)/4 ; l++  ){
        v2.push_back(boo) ;
    }
    boo = ! boo ;
    }


vector <int> v1 ;
boo = 1 ;
for (int l = 0 ; l < pow(2,k) ; l++ ){
    v1.push_back(boo) ;
    boo = ! boo ;
    }

/*
 for (const auto& element : v1) {
        std::cout << element << " ";
    }std::cout << " \n";
    for (const auto& element : v2) {
        std::cout << element << " ";
    }std::cout << " \n";
    for (const auto& element : v3) {
        std::cout << element << " ";
    }std::cout << " \n";
  */

///Vector that contains the 3 truth tables
vector < vector<int> > truthTables ;
truthTables.push_back(v1);
truthTables.push_back(v2);
truthTables.push_back(v3);

/*for (const auto& element : truthTables[2]) {
        std::cout << element << " ";
    }std::cout << " \n";
*/
cout<<"Main Characters: " ;
for (const auto& element : mainChar) {
        std::cout << element << " ";
    }std::cout << " \n";

vector <VarStruct> instances ;
    ///A B C
for (int i=0 ; i < (int) mainChar.size() ; i++){

 VarStruct obj(mainChar[i] , truthTables[i] );
 instances.push_back(obj) ;
}


cout<< instances[0].name ;
for (const auto& element : instances[0].truth_vector) {
        std::cout << element << " ";
    }std::cout << " \n";

cout<< instances[1].name ;
for (const auto& element : instances[1].truth_vector) {
        std::cout << element << " ";
    }std::cout << " \n";


cout<< instances[2].name ;
for (const auto& element : instances[2].truth_vector) {
        std::cout << element << " ";
    }std::cout << " \n";


    if ( (mainStr[0]>= 65 && mainStr[0] <=90) || (mainStr[0] >= 97 && mainStr[0] <=122)  ){

    if (mainStr[0] == instances[0].name && mainStr[2] == instances[1].name){  ///A K
            /*switch(mainStr[1]){
        case('^'):  ///A^K
            for (int i = 0 ; i < (int) instances[0].truth_vector.size()-1; i++  ){
            statement1_result [i] = instances[0].truth_vector[i] && instances[1].truth_vector[i];
            }
            break;
        case('v'):  ///AvK
            for (int i = 0 ; i < (int) instances[0].truth_vector.size()-1 ; i++  ){
            statement1_result [i] = instances[0].truth_vector[i] || instances[1].truth_vector[i];
            }
            break;

            default: cout<<"error" ;
            }*/

            cout<<"mainStr[0] == instances[0].name && mainStr[2] == instances[1].name " ;

    }

    else if (mainStr[0] == instances[0].name && mainStr[2] == instances[2].name){ ///A M

         /*switch(mainStr[1]){
        case('^'):  ///A^M
            for (int i = 0 ; i < (int) instances[0].truth_vector.size()-1 ; i++  ){
            statement1_result [i] = instances[0].truth_vector[i] && instances[2].truth_vector[i];
            }
            break;
        case('v'):  ///AvM
            for (int i = 0 ; i < (int) instances[0].truth_vector.size()-1 ; i++  ){
            statement1_result [i] = instances[0].truth_vector[i] || instances[2].truth_vector[i];
            }
            break;
            }*/
            cout<<"mainStr[0] == instances[0].name && mainStr[2] == instances[2].name" ;

    }

    else if (mainStr[0] == instances[1].name && mainStr[2] == instances[2].name){ ///K M
        /*switch(mainStr[1]){
        case('^'):  ///K^M
            for (int i = 0 ; i < (int) instances[0].truth_vector.size()-1 ; i++  ){
            statement1_result [i] = instances[1].truth_vector[i] && instances[2].truth_vector[i];
            }
            break;
        case('v'):  ///KvM
            for (int i = 0 ; i < (int) instances[0].truth_vector.size()-1 ; i++  ){
            statement1_result [i] = instances[1].truth_vector[i] || instances[2].truth_vector[i];
            }
            break;
            default: cout<<"error" ;
            }*/

            cout<<"mainStr[0] == instances[1].name && mainStr[2] == instances[2].name" ;
     }

    }else {

    ///if the first element is not
    switch(mainStr[0]){
    case('~'):
    for (int i = 0 ; i < (int) instances[0].truth_vector.size() ; i++  ){
        instances[0].truth_vector[i] = ! instances[0].truth_vector[i];
    }

    }
    cout<< instances[0].name ;
for (const auto& element : instances[0].truth_vector) {
        std::cout << element << " ";
    }std::cout << " \n";

    }

   /






/*
cout<<"is there other statements? (y/n)";
cin>> cont ;
if (cont == 'y' || cont == 'Y' ){
    cout<<"Enter the first statement: ";
    cin>>str ;

}else{


}*/


////Stack k ;
////k.push('K') ;
////k.push('A') ;
////k.push('T') ;
////cout << k.pop() ;








return 0;

}
