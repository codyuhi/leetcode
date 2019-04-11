class Solution {
public:
    bool processReg(string s, int & count){
        //cout << "Entered processReg" << endl;
        switch(s[0]){
            case ')':
                //cout << "Processed )" << endl;
                return true;
                break;
            case '(':
                s = s.substr(1,s.size()-1);
                count++;
                if(!processReg(s,count)){
                    return false;
                }
                break;
            case '[':
                s = s.substr(1,s.size()-1);
                count++;
                if(!processSqr(s,count)){
                    return false;
                }
                break;
            case '{':
                s = s.substr(1,s.size()-1);
                count++;
                if(!processCurl(s,count)){
                    return false;
                }
                break;
            default:
                return false;
                break;
        }
        return true;
    }
    bool processSqr(string s, int & count){
        //cout << "Entered processSqr" << endl;
        switch(s[0]){
            case ']':
                return true;
                break;
            case '(':
                s = s.substr(1,s.size()-1);
                if(!processReg(s,count)){
                    return false;
                }
                break;
            case '[':
                s = s.substr(1,s.size()-1);
                if(!processSqr(s,count)){
                    return false;
                }
                break;
            case '{':
                s = s.substr(1,s.size()-1);
                if(!processCurl(s,count)){
                    return false;
                }
                break;
            default:
                return false;
                break;
        }
        return true;
    }
    bool processCurl(string s, int & count){
        //cout << "Entered processCurl" << endl;
        switch(s[0]){
            case '}':
                return true;
                break;
            case '(':
                s = s.substr(1,s.size()-1);
                if(!processReg(s,count)){
                    return false;
                }
                break;
            case '[':
                s = s.substr(1,s.size()-1);
                if(!processSqr(s,count)){
                    return false;
                }
                break;
            case '{':
                s = s.substr(1,s.size()-1);
                if(!processCurl(s,count)){
                    return false;
                }
                break;
            default:
                return false;
                break;
            }        
        return true;
    }
    
    bool isValid(string s) {
        while(s != ""){
            int count = 0;
            if(s.length() > 0){
                switch(s[0]){
                    case '(':
                        s = s.substr(1,s.size()-1);
                        count++;
                        if(!processReg(s,count)){
                            //cout << "GOT HERE 0" << endl;
                            return false;
                        }
                        break;
                    case '[':
                        s = s.substr(1,s.size()-1);
                        count++;
                        if(!processSqr(s,count)){
                            return false;
                        }
                        break;
                    case '{':
                        s = s.substr(1,s.size()-1);
                        count++;
                        if(!processCurl(s,count)){
                            return false;
                        }
                        break;
                }
                //cout << "s is " << s << endl;
            }
            s = s.substr(count,s.size()-1);
        }
        return true;
    }
};
