const express = require('express')
const app = express()
const userModel = require('./models/user')
const postModel = require('./models/post')


app.get('/' , (req , res)=>{
    res.send('hey')
})

app.get('/create' , async (req , res)=>{
    let user = await userModel.create({
        name : 'Sumn',
        email : "suman@abc.com"
    })
    res.send(user)
})


const user1 = '66cde59cacf5ec922b5ffc0d'
const user2 = '66cde70ac0a8ef00d8ae6c84'

app.get('/post/user1' ,async (req , res)=>{
    let post = await postModel({
        postdata : "U1 - 2st msg- hey........",
        user : user1
    })

    let user = await userModel.findOne({_id : user1})
    user.posts.push(post._id)
    await user.save()
    res.send({post , user})
})

app.get('/post/user2' ,async (req , res)=>{
    let post = await postModel({
        postdata : "U2 - 2st msg- hey..Janu",
        user : user2
    })

    let user = await userModel.findOne({_id : user2})
    user.posts.push(post._id)
    await user.save()
    res.send({post , user})
})

app.get('/allpost' , async (req , res)=>{
    let post = await postModel.find({user : user1})
    res.send(post)
})

app.listen(3000 , () =>{console.log("Server running at 3000")})