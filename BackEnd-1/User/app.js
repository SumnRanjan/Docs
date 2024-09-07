const express = require('express')
const app = express()
const path = require('path')
const userModel = require('./models/user')

app.use(express.json())
app.use(express.urlencoded({ extended: true }))
app.use(express.static(path.join(__dirname, 'public')))

app.set('view engine', 'ejs')

app.get('/', (req, res) => {
    res.render("index")
})
    

app.get('/user', async (req, res) => {
    let users = await userModel.find()
    res.render('user' , {users})
})

app.post('/create', async (req, res) => {
    let { name, email, image } = req.body
    let userCreated = await userModel.create({ name, email, image })
    res.redirect('/user')
})

app.get('/edit/:id' , async (req,res)=>{
    let user = await userModel.findOne({_id : req.params.id})
    res.render('edit' , {user})
})

app.post('/update/:id', async (req, res) => {
    let { name, email, image } = req.body
    let user = await userModel.findOneAndUpdate({_id : req.params.id} , {name , email , image} , {new : true})
    res.redirect('/user')
})

app.get('/delete/:id' , async (req , res) =>{
    let user = await userModel.findOneAndDelete({_id : req.params.id})
    res.redirect('/user')
})

app.listen(3000, () => { console.log("Server Listening at 3000") })