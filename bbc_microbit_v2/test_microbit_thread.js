
var udp=require('dgram');
// -------------------- udp client ----------------

var buffer = require('buffer');

// creating a client socket
var client = udp.createSocket('udp6');

//buffer msg

client.on('message',function(msg,info){
  console.log('Data received from server : ' + msg.toString());
  console.log('Received %d bytes from %s:%d\n',msg.length, info.address, info.port);
});
//sending msg
    
var data = Buffer.from([0x1f,0x0,0x32,0x33]);

client.send(data,4242,'fd96:5e1e:4749:1:1fdb:ff05:1113:b755',function(error){
    if(error){
        client.close();
    } else{
        console.log('Data sent !!!');
    }
});

