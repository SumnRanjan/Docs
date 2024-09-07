const http = require('http')

//simple server
// const server = http.createServer((req, res) => {
//     res.end('Hello ')
// })

//Routing
// const server = http.createServer((req , res) =>{
//     if(req.url === '/'){
//         res.end('This is a home Page')
//     }else if(req.url === '/about'){
//         res.end('This is about Page')
//     }else if(req.url === '/contact'){
//         res.end('This is about Page')
//     }else{
//         res.end("Page Not FOUND")
//     }
// })

//Modified code
const server = http.createServer((req , res) =>{
    if(req.url === '/'){
        res.writeHead(200 , {'content-type' : 'text/html'})
        res.write('<h1>Home Page</h1>')
        res.end()
    }else if(req.url === '/about'){
        res.writeHead(200 , {'content-type' : 'text/html'})
        res.write('<h1>About Page</h1>')
        res.end()
    }else if(req.url === '/contact'){
        res.writeHead(200 , {'content-type' : 'text/html'})
        res.write('<h1>Contact Page</h1>')
        res.end()
    }else{
        res.writeHead(200 , {'content-type' : 'text/html'})
        res.write('<h1>404 Page Not Found</h1>')
        res.end()
    }
})

server.listen(3000, () => {
    console.log("Server listening at port 3000")
})

