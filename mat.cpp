//
// Created by Amit on 05/03/2022.
//
/**
 * This mat file is the main file of the program.
 * We will have here a main mat function that will get width length and 2 symbols and will create our custom mat.
 * * Author: Amit Melamed
 */
#include <iostream>
#include <string>
#include "mat.hpp"
using namespace std;

namespace ariel{


        string mat(int a,int b,char c,char d){
        //matrix size should be odd
        if(a%2==0||b%2==0){
            throw std::invalid_argument( "Mat size is always odd" );
        }
        if(a<1||b<1){
            throw std::invalid_argument( "received negative or zero matrix values" );
        }
        if(c==d){
            throw std::invalid_argument( "symbols must be different" );
        }
        if (c==' ' || d==' ' || c=='\n'|| d=='\n'||c=='\t'|| d=='\t'|| c=='\r'|| d=='\r'){
            throw std::invalid_argument( "space, backslash n/t/r now allowed" );

        }


        
            char matrix [b][a];
            for (int i = 0; i <b ; ++i) {
                for (int j = 0; j < a; ++j) {
                    matrix[i][j]=c;
                }
            }
            if(a!=1){
                for (int i = 1; i <b ; i=i+2) {
                    for (int j = i; j < b-i; ++j) {
                        matrix[j][i]=d;
                        matrix[j][a-i-1]=d;
                    }
                }
            }
            if(b!=1){
                for (int i = 1; i <a ; i=i+2) {
                    for (int j = i; j < a-i; ++j) {
                        matrix[i][j]=d;
                        matrix[b-i-1][j]=d;

                    }
                }
            }






            std::string finalstr="";
            for (int i = 0; i < b; ++i) {
                for (int j = 0; j < a; ++j) {
                    finalstr.push_back(matrix[i][j]);
                }
                finalstr.push_back('\n');
            }
        return finalstr;
    }

}





