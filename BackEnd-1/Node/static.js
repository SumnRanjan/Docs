const http = require('http')
const fs = require('fs')


//import Files
const homePage = fs.readFileSync('./public/index.html')
const homeStyle = fs.readFileSync('./public/style.css')
const homeImage = fs.readFileSync('./public/zoro.png')


//Create Server
const server = http.createServer((req, res) => {
    console.log(req.url)
    if (req.url === '/') {
        res.writeHead(200, { 'content-type': 'text/html' })
        res.write(homePage)
        res.end()
    }else if (req.url === '/style.css') {
        res.writeHead(200, { 'content-type': 'text/css' })
        res.write(homeStyle)
        res.end()
    }else if (req.url === '/zoro.png') {
        res.writeHead(200, { 'content-type': 'image/png' })
        res.write(homeImage)
        res.end()
    }else if (req.url === '/about') {
        res.writeHead(200, { 'content-type': 'text/html' })
        res.write('<h1>About Page</h1><a href"/">Home</a>')
        res.end()
    } else if (req.url === '/contact') {
        res.writeHead(200, { 'content-type': 'text/html' })
        res.write('<h1>Contact Page</h1><a href"/">Home</a>')
        res.end()
    } else {
        res.writeHead(200, { 'content-type': 'text/html' })
        res.write('<h1>404 Page Not Found</h1><a href"/">Home</a>')
        res.end()
    }
})

server.listen(3000, () => {
    console.log("Server listening at port 3000")
})

