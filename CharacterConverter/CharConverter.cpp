#include "stdafx.h"
#include "CharConverter.h"
	
	string CharConverter::uppercase(string userinput){
		int str = userinput.length();
		for (int i = 0; i < str; i++){
			for (int j = 0; j < 26; j++){
				userinput[i] = toupper(userinput[i]);
			}
		}
		return userinput;
	}

	string CharConverter::properWords(string userinput){
		int str = userinput.length();
		for (int i = 0; i < str; i++){
			if (i == 0 || userinput[i - 1] == ' '){
				userinput[i] = toupper(userinput[i]);
				
			}
		}
		return userinput;
	}
