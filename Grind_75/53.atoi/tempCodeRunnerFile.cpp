while (s[i] <'0' || s[i] > '9'){
        res = res*10 + (s[i] -'0');
        i++;
        if (sign*res < INT_MIN) return INT_MIN;
        if (sign*res > INT_MAX) return INT_MAX;
        
    }