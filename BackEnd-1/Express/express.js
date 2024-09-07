const express = require('express')
const app = express()

//Middleware
app.use(function(req , res , next) {
    console.log("Middle ware........1")
    next()
})

app.use(  '/about',function( req , res , next) {
    console.log("Middle ware........2")
    next()
})

app.use(function(req , res , next) {
    console.log("Middle ware........3")
    next()
})


app.get('/' , function(req , res){
    res.send('Home Page')
})

app.get('/about' , function(req , res){
    res.send('About Page')
})

app.get('/profile' , function(req , res , next){
    return next(new Error('Something went wrong...'))
})

app.use(function(err , req , res , next){
    console.log(err.stack)
    res.status(500)
    res.send("Error 500! ")
})

app.listen(3000 , ()=> console.log('Server listing at port 3000'))