const express = require('express')
const app = express()
const cookieParser = require('cookie-parser')
const path = require('path')
const userModel = require('./models/user')
const bcrypt = require('bcrypt')
const jwt = require('jsonwebtoken')

app.use(express.json())
app.use(express.urlencoded({ extended: true }))
app.use(express.static(path.join(__dirname, 'public')))
app.use(cookieParser())
app.set('view engine', 'ejs')

app.get('/', (req, res) => {
    res.render('index')
})

app.post('/create', (req, res) => {
    let { username, email, password, age } = req.body
    const saltRound = 10
    bcrypt.genSalt(saltRound, (err, salt) => {
        bcrypt.hash(password, salt, async (err, hash) => {
            let userCreated = await userModel.create({
                username,
                email,
                password: hash,
                age
            })

            let token = jwt.sign({ email }, "secretKey")
            res.cookie('token', token)

            res.send(userCreated)
        })
    })
})

app.get('/logout', (req, res) => {
    res.cookie('token', '')
    res.redirect('/')
})

app.get('/login', (req, res) => {
    res.render('login')
})

app.post('/login', async (req, res) => {
    let user = await userModel.findOne({ email: req.body.email })
    if (!user) {
        res.render('error')
    }

    bcrypt.compare(req.body.password, user.password, (err, result) => {
        if (result) {
            let token = jwt.sign({ email: user.email }, "secertKey")
            res.cookie('token', token)
            res.render('profile')
        } else {
            res.render('error')
        }
    })

})


app.listen(3000, () => console.log("Server listening at port 3000"))
