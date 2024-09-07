const express = require('express')
const cookieParser = require('cookie-parser')

const app = express()

app.use(cookieParser())

app.get('/setCookies', (req, res) => {
    res.cookie('Token Name', 'Encrypted cookie string value', {
        // maxAge: 60000,
        secure: true,
        httpOnly: true,
        sameSite: 'Strict',
    });
    res.send('Cookie has been saved');
});

app.get('/getCookies', (req, res) => {
    console.log(req.cookies);
    res.send(req.cookies);
});

app.get('/deleteCookie', (req, res) => {
    res.clearCookie('Token Name')
    res.send('cookie Deleted')
})

app.listen(3000, () => console.log('Server listing at port 3000'))