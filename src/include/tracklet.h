

#include "kalman_filter.h"
#include <vector>
#include "pairing.h" // includes Eigen
using namespace std;


#ifndef TRACKLET_H
#define TRACKLET_H

class Tracklet {
public:
    Tracklet(int ID,
             VectorXd initial_detection,
             KalmanFilter kf);

    VectorXd getState(); // either returns KF state OR last measurement if KF not initialised

    void updateTracklet(Pairing pairing); // update the tracklet with a new pairing

    int getNumConsecutiveMisses() { return num_consecutive_misses;};
    void recordMiss(){num_consecutive_misses++;}; // increment number of consecutive misses
    int getID(){return ID_;};

    double getDistance(VectorXd detection);// return the distance to this detection
    int getLength(){return tracklet_length_;}; // return the number of detections registered with this tracklet
    bool isInitialised() {return isInitialised_;}; // have we started the kalman_filter?
    void initKf(); // initialise the kalman filter at the last observation
    KalmanFilter getKf() {return kf_;}; // get the private kalman filter

private:
    KalmanFilter kf_; // private copy of kalman filter
    int ID_;
    int num_consecutive_misses = 0;
    int tracklet_length_ = 1; // number of detections registered with this tracklet. We start with 1 detection
    vector <VectorXd> detection_vector_;
    bool isInitialised_ = false; // have we started the kalman_filter?

};

#endif // TRACKLET_H