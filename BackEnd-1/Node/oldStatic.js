const http = require('http');
const fs = require('fs');
const path = require('path');

const server = http.createServer(function (req, res) {
    if (req.url === '/') {
        fs.readFile(path.join(__dirname, 'public', 'index.html'), 'utf-8', function (err, data) {
            res.writeHead(200, { 'content-type': 'text/html' });
            res.end(data);
        });
    } else if (req.url.match("\.css$")) {
        const cssPath = path.join(__dirname, 'public', req.url);
        const fileStream = fs.createReadStream(cssPath, 'utf-8');
        res.writeHead(200, { 'content-type': 'text/css' });
        fileStream.pipe(res);
    } else if (req.url.match("\.png$")) {
        const imgPath = path.join(__dirname, 'public', req.url);
        const fileStream = fs.createReadStream(imgPath);
        res.writeHead(200, { 'content-type': 'image/png' });
        fileStream.pipe(res);
    } else if (req.url === '/about.html') {
        fs.readFile(path.join(__dirname, 'public', 'about.html'), 'utf-8', function (err, data) {
            res.writeHead(200, { 'content-type': 'text/html' });
            res.end(data);
        });
    } else if (req.url === '/contact.html') {
        fs.readFile(path.join(__dirname, 'public', 'contact.html'), 'utf-8', function (err, data) {
            res.writeHead(200, { 'content-type': 'text/html' });
            res.end(data);
        });
    } else {
        res.writeHead(200, { 'content-type': 'text/html' });
        res.write('<h1>404 Page Not Found</h1> <a href="/">Home</a>');
        res.end();
    }
});

server.listen(3000, () => console.log("server listening at port 3000"));
