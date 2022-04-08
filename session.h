#ifndef SESSION_H
#define SESSION_H


typedef enum {META, SUBDELTA, DELTA, THETA,NON} sessionNumType;
class Session {

    public:
    	Session();
    	int increaseIntensity();
    	int decreaseIntensity();
        int nextSession();
        int previousSession();
        void setType(sessionNumType newType);
    
    private:
    	int intensity;
        sessionNumType type;
};
#endif
