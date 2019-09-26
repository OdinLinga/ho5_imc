#include <IMC/Spec/Abort.hpp>
#include <IMC/Base/ByteBuffer.hpp>
#include <IMC/Base/Packet.hpp>
#include <IMC/Spec/PlanSpecification.hpp>
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


    PlanSpecification ps;
    ps.setTimeStamp(1.5628304294681385E9);
    ps.setSource(16652);
    ps.setSourceEntity(44);
    ps.setDestination(30);
    ps.setDestinationEntity(255);
    ps.plan_id = "cmd-lauv-xplore-1";
    ps.start_man_id = "1";

    std::cout << ps.toString();


    socket.sendTo(buffer, size, localhost);                 //send message to localhost:6002
    std::cout << "Program Finished!" << std::endl;          //Just so i know the program runs.
    return 0;
}