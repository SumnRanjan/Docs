const express = require('express');
const session = require('express-session');

const app = express();

app.use(session({
    secret: 'secret-key', //Secert Key use to sign the session ID cookie
    resave: false,  // Whether to save the session data if no changes are made
    saveUninitialized: false, // Whether to save Uninitialized session
    cookie:{maxAge:5000} // Session timeout of 5 sec
}));

app.get('/setSession', (req, res) => {
    req.session.username = 'Sam'
    res.send('Session data set')
})

app.get('/getSession', (req, res) => {
    const username = req.session.username
    res.send(`Username : ${username}`)
})

app.get('/destroySession', (req, res) => {
    req.session.destroy()
    res.send(`Session Destroy`)
})


app.listen(3000, () => console.log('Server listening at port 3000'));
