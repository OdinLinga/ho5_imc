#include <IMC/Spec/Abort.hpp>
#include <IMC/Base/ByteBuffer.hpp>
#include <IMC/Base/Packet.hpp>
#include <IMC/Spec/PlanSpecification.hpp>
#include <IMC/Spec/PlanManeuver.hpp>
#include <IMC/Spec/Loiter.hpp>
#include <IMC/Spec/SetEntityParameters.hpp>
#include <IMC/Spec/EntityParameter.hpp>
#include <IMC/Base/MessageList.hpp>
#include <IMC/Base/InlineMessage.hpp>
#include <IMC/Base/Message.hpp>
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

    PlanManeuver pm;
    pm.maneuver_id = "1";
    Loiter loiter;
    loiter.timeout = 10000;
    loiter.lat = 0.7188016469344056;
    loiter.lon = -0.15194250254286037;
    loiter.z = 3;
    loiter.z_units = 1;
    loiter.duration = 300;
    loiter.speed = 1000;
    loiter.speed_units = 1;
    loiter.type = 1;
    loiter.radius = 20;
    loiter.length = 1;
    loiter.bearing = 0;
    loiter.direction = 1;
    EntityParameter ep;
    MessageList<EntityParameter> params;
    SetEntityParameters sep;
    sep.name = "LBL";
    ep.name = "Active";
    ep.value = "false";
    params.push_back(ep);
    sep.params = params;
    InlineMessage<Maneuver> data;
    data.set(loiter);
    pm.data = data;

    MessageList<Message> s_actions;
    s_actions.push_back(sep);
    pm.start_actions = s_actions;
    MessageList<PlanManeuver> maneuvers;
    maneuvers.push_back(pm);
    ps.maneuvers = maneuvers;
    ps.toJSON(std::cout);

    socket.sendTo(buffer, size, localhost);                 //send message to localhost:6002
    std::cout << "Program Finished!" << std::endl;          //Just so i know the program runs.
    return 0;
}