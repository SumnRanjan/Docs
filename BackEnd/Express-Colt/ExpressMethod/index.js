const express = require('express')
const app = express()


// app.use((req, res) => {
//     console.log("We Got a new request")
//     // res.send("Hello  , we got your req This a res")
//     // res.send({color : 'red'})
//     // res.send("<h1> THIS IS MY WEBPAGE </h1>")
// })

app.get('/' , (req , res) =>{
    res.send('This is Home Page')
})

app.get('/r/:subreddit' , (req , res)=>{
    // res.send("This is Subreddit")
    // console.log(req.params)
    const {subreddit} = req.params
    res.send(`<h1> Browsing the ${subreddit} subreddit `)

})

app.get('/r/:subreddit/:postId' , (req , res)=>{
    const {subreddit , postId} = req.params
    res.send(`<h1> Viewing Post Id: ${postId} on ${subreddit} subreddit `)

})

app.get('/cats' , (req , res) =>{
    res.send('Meowwwwwwww')
})

app.post('/cats' , (req , res) =>{
    res.send('Post req This is different from get ')
})

app.get('/Dogs' , (req , res) =>{
    res.send('Woffs')
})

//query string
app.get('/search' , (req , res) =>{
    // console.log(req.query)
    // res.send('hii')
    const { q } = req.query
    if(!q){
        res.send("nothing found nothing search")
    }
    res.send(` <h1> Search results for : ${q} </h1> `)

})
 
app.get('*' , (req , res) =>{     
    res.send('I dont Know that the path')
})

app.listen(3000, () => { console.log("listening at port 3000")})