const express = require('express')
const app = express()
const path = require('path')
const redditdata = require('./data.json')

app.set('view engine', 'ejs')
app.set('views', path.join(__dirname, '/views')) //use when u want to run in cd .. dir

app.use(express.static('public'))
app.use(express.static(path.join(__dirname, 'public'))) //abs path use when u want to run in cd .. dir

app.get('/', (req, res) => {
    res.render('home')
})

app.get('/cats', (req, res) => {
    const cats = ['Blue', 'Rocket', 'Monty', 'Lolo', 'Love']
    res.render('cats', { cats }) 
})

app.get('/rand', (req, res) => {
    const num = Math.floor(Math.random() * 10) + 1
    // res.render('random', { random: num })  
    res.render('random', { num })
})

app.get('/r/:subreddit', (req, res) => {
    const { subreddit } = req.params;
    const data = redditdata[subreddit]
    if (data) {
        res.render('subreddit', { ...data })
    }
    else {
        res.render('notfound', { subreddit })
    }
})

app.listen(3000, () => console.log("LISTENING ON PORT 3000"))