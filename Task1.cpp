#include<iostream>
#include<vector>
#include<math.h>


using namespace std ;



class VarStruct{
private:
char name ;
vector <int> truth_vector ;
public:


VarStruct(){}

VarStruct(char varName ,vector <int> truth_vec ){
this ->name = varName ;
this ->truth_vector = truth_vec ;
}


char getName(){
return this->name;
}

vector <int> getVector(){
return this->truth_vector;
}

void setVector(int pos , int value ){
this->truth_vector[pos] =  value ;
}


};

vector <int> calculate (string str1) ;
vector <VarStruct> instances ;
vector <int> statement1_result ;   ///save the truth vector of the first statement
vector <int> statement2_result ;   ///save the truth vector of the second statement


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


vector <int> notVector(vector <int> v){
    vector <int> vNot ;
    for (int i = 0 ; i <= (int) v.size()-1 ; i++  ){
        vNot.push_back(!v[i]);
        }
return vNot ;
}



bool containBracket(string str){

return str.find('(') != string::npos ;  /// if no bracket find() will return npos
}



int main(){

string str1;
string str2;
string mainStr;

vector <char> mainChar ;



bool repeated ;
VarStruct var1 ;
VarStruct var2 ;
VarStruct var3 ;

cout<<"Enter first statement: ";
cin>>str1 ;
cout<<"Enter second statement: ";
cin>>str2 ;
mainStr = str1 + str2 ;

cout<<"Conc input: " ;
cout<<mainStr<<endl;

for (char element : mainStr){
    repeated = 0 ;
    if( (element >= 65 && element <=90) || (element >= 97 && element <=122) ) ///check for characters from a->z or from A->Z
        {

        for (int i=0 ; i <= (int) mainChar.size()-1 ; i++){
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
cout<<"Variables: " ;
 for (const auto& element : mainChar) {
        std::cout << element << " ";
    }std::cout << " \n";


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


///Truth table that contains the 3 truth vectors
vector < vector<int> > truthTable ;
truthTable.push_back(v1);
truthTable.push_back(v2);
truthTable.push_back(v3);




    ///if the 3 variables are A K M; we will give each of them a truth vector; to construct an initial truth table of 3 variables

vector <VarStruct> instances ;

for (int i=0 ; i <= (int) mainChar.size()-1 ; i++){
cout<<i<<endl ;
 VarStruct obj(mainChar[i] , truthTable[i] );
 instances.push_back(obj) ;
}


cout<< instances[0].getName()<<" " ;
for (const auto& element : instances[0].getVector()  ) {
        std::cout << element << " ";
    }std::cout << " \n";

cout<< instances[1].getName() <<" " ;
for (const auto& element : instances[1].getVector()  ) {
        std::cout << element << " ";
    }std::cout << " \n";


cout<< instances[2].getName() <<" " ;
for (const auto& element : instances[2].getVector()  ) {
        std::cout << element << " ";
    }std::cout << " \n";

cout<<"str1: "<<str1<<endl;
cout<<"str2: "<<str2<<endl;
if ((int)str1.size()==3 ){
    vector <int> statement1_result11 = calculate (str1);

    cout<<"egababaa" ;
    for (const auto& element : statement1_result11) {
            std::cout << element << " ";
    }       std::cout << " \n";}


    return 0 ;

}












////////////////Getting the truth table of the first statement


vector <int> calculate (string str1){


   // if ( (str1[0]>= 65 && str1[0] <=90) || (str1[0] >= 97 && str1[0] <=122)  ) { ///Check if the first char is a variable not a NOT gate


cout<<"str1[0]= "<<str1[0]<< " instances[0]="<<instances[0].getName()<<"str1[2]= "<<str1[2]<< " instances[1]="<<instances[1].getName()<<endl ;

    if ( (str1[0] == instances[0].getName()) && (str1[2] == instances[1].getName())   ) {  ///A K

        cout<<"tmammmm";

            switch(str1[1]){
        case('^'):  ///A^K
            for (int i = 0 ; i <= (int) instances[0].getVector().size()-1; i++  ){
            statement1_result.push_back(  (instances[0].getVector()[i])  && ( instances[1].getVector()[i] )   )   ;
            }
            break;
        case('v'):  ///AvK
            for (int i = 0 ; i <= (int) instances[0].getVector().size()-1 ; i++  ){
            statement1_result.push_back(  (instances[0].getVector()[i])  || ( instances[1].getVector()[i] )   ) ;
            }
            break;

            default: cout<<"error" ;
            }

            cout<<"str1[0] == instances[0].getName() && str1[2] == instances[1].getName() " <<endl;
            for (const auto& element : statement1_result) {
            std::cout << element << " ";
    }       std::cout << " \n";



    }

    else if (str1[0] == instances[0].getName() && str1[2] == instances[2].getName()){ ///A M

         switch(str1[1]){
        case('^'):  ///A^M
            for (int i = 0 ; i <= (int) instances[0].getVector().size()-1 ; i++  ){
            statement1_result [i] = instances[0].getVector()[i] && instances[2].getVector()[i];
            }
            break;
        case('v'):  ///AvM
            for (int i = 0 ; i <= (int) instances[0].getVector().size()-1 ; i++  ){
            statement1_result [i] = instances[0].getVector()[i] || instances[2].getVector()[i];
            }
            break;
            }

            cout<<"str1[0] == instances[0].getName() && str1[2] == instances[2].getName()" <<endl;
            for (const auto& element : statement1_result) {
            std::cout << element << " ";
    }       std::cout << " \n";

    }

    else if (str1[0] == instances[1].getName() && str1[2] == instances[2].getName()){ ///K M
        switch(str1[1]){
        case('^'):  ///K^M
            for (int i = 0 ; i <= (int) instances[0].getVector().size()-1 ; i++  ){
            statement1_result [i] = instances[1].getVector()[i] && instances[2].getVector()[i];
            }
            break;
        case('v'):  ///KvM
            for (int i = 0 ; i <= (int) instances[0].getVector().size()-1 ; i++  ){
            statement1_result [i] = instances[1].getVector()[i] || instances[2].getVector()[i];
            }
            break;
            default: cout<<"error" ;
            }

            cout<<"str1[0] == instances[1].getName() && str1[2] == instances[2].getName()" <<endl;
            for (const auto& element : statement1_result) {
            std::cout << element << " ";
    }       std::cout << " \n";}

    return statement1_result ;


    }


    /*else if ( (str1[0] == '~') && ( (str1[1] >= 65 && str1[1] <=90) || (str1[0] >= 97 && str1[0] <=122)   )  ) {   ///if the first char is NOT gate; and the 2nd char is a variable not a '('

    for (int i = 0 ; i <= (int) instances[0].getVector().size()-1 ; i++  ){
        instances[0].setVector(i , !(instances[0].getVector()[i]) ) ;   ///Toggeling the truth vector of the variable
    }

    cout<<endl<<endl<<endl<<endl;
    cout<< instances[0].getName()<<" " ;
    for (const auto& element : instances[0].getVector()) {
        std::cout << element << " ";
    }std::cout << " \n";

    }
    else if( containBracket(str1) ){  ///if the first char is NOT gate; and the 2nd char is a '('

    int startStr = str1.find('(');
    int endStr = str1.find(')');
    string subStr1 = str1.substr(startStr , endStr - startStr + 1 ) ;
    vector <int> Notvetor = notVector()


    }*/


















    //cout<<"str2: "<< str2 <<endl;

    /*

    if ( (str2[0]>= 65 && str1[0] <=90) || (str1[0] >= 97 && str1[0] <=122)  ) { ///Check if the first char is a variable not a NOT gate


cout<<"str1[0]= "<<str1[0]<< " instances[0]="<<instances[0].getName()<<"str1[2]= "<<str1[2]<< " instances[1]="<<instances[1].getName()<<endl ;

    if ( (str1[0] == instances[0].getName()) && (str1[2] == instances[1].getName())   ) {  ///A K

        cout<<"tmammmm";

            switch(str1[1]){
        case('^'):  ///A^K
            for (int i = 0 ; i <= (int) instances[0].getVector().size()-1; i++  ){
            statement1_result.push_back(  (instances[0].getVector()[i])  && ( instances[1].getVector()[i] )   )   ;
            }
            break;
        case('v'):  ///AvK
            for (int i = 0 ; i <= (int) instances[0].getVector().size()-1 ; i++  ){
            statement1_result.push_back(  (instances[0].getVector()[i])  || ( instances[1].getVector()[i] )   ) ;
            }
            break;

            default: cout<<"error" ;
            }

            cout<<"str1[0] == instances[0].getName() && str1[2] == instances[1].getName() " <<endl;
            for (const auto& element : statement1_result) {
            std::cout << element << " ";
    }       std::cout << " \n";



    }

    else if (str1[0] == instances[0].getName() && str1[2] == instances[2].getName()){ ///A M

         switch(str1[1]){
        case('^'):  ///A^M
            for (int i = 0 ; i <= (int) instances[0].getVector().size()-1 ; i++  ){
            statement1_result [i] = instances[0].getVector()[i] && instances[2].getVector()[i];
            }
            break;
        case('v'):  ///AvM
            for (int i = 0 ; i <= (int) instances[0].getVector().size()-1 ; i++  ){
            statement1_result [i] = instances[0].getVector()[i] || instances[2].getVector()[i];
            }
            break;
            }

            cout<<"str1[0] == instances[0].getName() && str1[2] == instances[2].getName()" <<endl;
            for (const auto& element : statement1_result) {
            std::cout << element << " ";
    }       std::cout << " \n";

    }

    else if (str1[0] == instances[1].getName() && str1[2] == instances[2].getName()){ ///K M
        switch(str1[1]){
        case('^'):  ///K^M
            for (int i = 0 ; i <= (int) instances[0].getVector().size()-1 ; i++  ){
            statement1_result [i] = instances[1].getVector()[i] && instances[2].getVector()[i];
            }
            break;
        case('v'):  ///KvM
            for (int i = 0 ; i <= (int) instances[0].getVector().size()-1 ; i++  ){
            statement1_result [i] = instances[1].getVector()[i] || instances[2].getVector()[i];
            }
            break;
            default: cout<<"error" ;
            }

            cout<<"str1[0] == instances[1].getName() && str1[2] == instances[2].getName()" <<endl;
            for (const auto& element : statement1_result) {
            std::cout << element << " ";
    }       std::cout << " \n";}

    }else if ( (str1[0] == '~') && ( (str1[1] >= 65 && str1[1] <=90) || (str1[0] >= 97 && str1[0] <=122)   )  ) {   ///if the first char is NOT gate; and the 2nd char is a variable not a '('

    for (int i = 0 ; i <= (int) instances[0].getVector().size()-1 ; i++  ){
        instances[0].setVector(i , !(instances[0].getVector()[i]) ) ;   ///Toggeling the truth vector
    }

    cout<<endl<<endl<<endl<<endl;
    cout<< instances[0].getName()<<" " ;
    for (const auto& element : instances[0].getVector()) {
        std::cout << element << " ";
    }std::cout << " \n";

    }



*/






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

