#include <IMC/Spec/Abort.hpp>
#include <IMC/Base/ByteBuffer.hpp>
#include <IMC/Base/Packet.hpp>
// see https://github.com/butcherg/DatagramSocket
#include <Socket/DatagramSocket.h>
#include <iostream> //For printing
#define LAUVXPLORE1 (30)

using namespace IMC;

int main()
{
    char localhost[] = "127.0.0.1";
    Abort abort;                                    //Create Abort message
    abort.setTimeStamp();                           //set timestamp to current time
    abort.setDestination(LAUVXPLORE1);              //specify destination
    int size = abort.getSerializationSize();        //calculate bytes required for serialization
    char buffer[size];                              //allocate same number of bytes


    Packet::serialize(&abort, (uint8_t *) buffer, size);    //serialize message
    DatagramSocket socket(6002, localhost, true, true);     //create socket




    
    socket.sendTo(buffer, size, localhost);                 //send message to localhost:6002
    std::cout << "Program Finished!" << std::endl;          //Just so i know the program runs.
    return 0;
}