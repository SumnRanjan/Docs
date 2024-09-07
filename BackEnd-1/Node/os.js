const os = require('os')

const sysuptime = os.uptime()
console.log(sysuptime)

const userinfo = os.userInfo()
console.log(userinfo)

const otherInfo  = {
    cpu : os.arch(),
    name : os.type(),
    paltform : os.platform(),
    release : os.release(),
    hostname : os.hostname(),
    totaMemory : os.totalmem(),
    freeMemory : os.freemem(),
    network : os.networkInterfaces()
}

console.log(otherInfo)