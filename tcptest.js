const assert = require("assert"),
    fs = require("fs"),
    os = require("os"),
    path = require("path")
const net = require('net')


const myIP = "127.0.0.1"
const PORT = 8888
let maxpacketsize = 32*1024


let size = 1024 * 128 + 3


let src = new Float32Array(size)
for (let i=0; i<size; i++) src[i]=i
console.log(src, src.byteLength)

let destination = new Float32Array(size)
let didx = 0

let sockets = []

const server = net.createServer()
server.on('error', (error) => {
    log("tcp_server", "error", error)
    server.close()
})

server.on('connection', sock => {
    sockets.push(sock)

    sock.on('data', msg => {
        // this would be registering the socket for certain names?
        console.log(msg)
        
        // 
    })

	sock.on('close', data => {
        
		console.log("tcp_server", "info", `Socket closed with ${sock.remoteAddress}:${sock.remotePort}`)
	})	
})

server.listen(PORT, myIP, () => {
    const address = server.address()
    console.log("tcp_server", "info", 'Server is listening at port ' + address.port)
    console.log("tcp_server", "info", 'Server ip :' + address.address)
    console.log("tcp_server", "info", 'Server is IP4/IP6 : ' + address.family)
})

function sendData(data) {
    let bytes = new Uint8Array(data.buffer)
    
    // break this up into chunks, and send each chunk
    // each chunk needs a header to identify length & offset
    // Use Uint32 for length & offset
    let header_bytelength = 4*4
    let max_body_bytelength = maxpacketsize - header_bytelength

    let msg = new Uint8Array(maxpacketsize)
    let header = new Uint32Array(msg.buffer, 0, 4)

    for (let i=0; i<bytes.byteLength; i += max_body_bytelength) {

        let msg_body_bytelength = Math.min(max_body_bytelength, bytes.byteLength - i)
        header[0] = msg_body_bytelength  // bytes in this message body
        header[1] = i // offset into destination
        header[2] = bytes.length  // total destination size

        //console.log("send", header)

        msg.set(bytes.subarray(i, i+msg_body_bytelength), header_bytelength)

        
    }

    for (let sock of sockets) {
        sock.write(bytes)
    }
}

const client = new net.Socket()
const host = myIP

client.connect(PORT, host, function() {
    console.log('Client connected')
})

client.on('data', buf => {
    let msgbytelength = buf.byteLength
    //console.log('Received: ' + msgbytelength)

    let dst = new Uint8Array(destination.buffer)

    // copy in two parts:
    let part1 = Math.min(msgbytelength, dst.byteLength - msgbytelength)
    let part2 = msgbytelength - part1

    dst.set(buf, didx, part1)
    didx += part1;
    if (didx >= dst.byteLength) didx = 0;
    if (part2) {
        dst.set(buf, didx, part2)
        didx += part2;
    }
    console.log(didx)

    //client.destroy()
})

client.on('close', () => {
    console.log('Client connection closed')
})


setInterval(()=>{
    sendData(src)
}, 100);
