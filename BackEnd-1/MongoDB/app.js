const express = require('express')
const userModel = require('./userModel')
const { Aggregate } = require('mongoose')
const app = express()

app.get('/', (req, res) => {
    res.send("hello")
})

//CRUD MONGOOSE 
//Create
app.get('/create', async (req, res) => {
    let userCreated = await userModel.create({
        name: "Suman",
        email: "Sam@abc.com",
        age: 34
    })
    res.send(userCreated)
})

//Read
app.get('/read', async (req, res) => {
    let users = await userModel.find()
    res.send(users)
})

//Update
app.get('/delete' , async(req , res)=>{
    let userDeleted = await userModel.findOneAndDelete({name : "Suman"})
    res.send(userDeleted)
})

//Delete
app.get('/delete' , async(req , res)=>{
    let userUpdated = await userModel.findOneAndUpdate({name : "Suman"} , {age : 21} , {new : true})
    res.send(userUpdated)
})


app.listen(3000, () => { console.log("Server Listening at 3000") })