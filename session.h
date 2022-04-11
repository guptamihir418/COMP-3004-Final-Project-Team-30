#ifndef SESSION_H
#define SESSION_H


typedef enum {MET, SUBDELTA, DELTA, THETA,NON} sessionNumType;
class Session {

    public:
        Session();
        int increaseIntensity();
        int decreaseIntensity();
//        int nextSession();
//        int previousSession();
        void setType(sessionNumType newType);
        sessionNumType getType();
        float getDuration();
        int getIntensity();
        void setDuration(float dur);

    private:
        int intensity;
        sessionNumType type;
        float duration;
};
#endif
