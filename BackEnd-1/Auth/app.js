const express = require('express')
const cookieParser = require('cookie-parser')
const app = express() 
// const bcrypt = require('bcrypt')
const jwt = require('jsonwebtoken')

app.use(cookieParser())



app.get('/' , (req,res)=>{
    let token = jwt.sign({email: "abc@abc.com"} , "secretKey")
    res.cookie('token' , token)
    console.log(token)
    res.send("Cookies Created");
})

app.get('/read' , (req , res)=>{
    let data = jwt.verify(req.cookies.token , "secretKey")
    res.send(data)
})

// const saltRounds = 10;
// const pass = "pass123";


// app.get('/' , (req , res)=>{
//     bcrypt.genSalt(saltRounds , (err , salt)=>{
//         bcrypt.hash(pass , salt , (err , hash)=>{
//             console.log("Salt - " + salt)
//             console.log("Password - " + hash)
//         })
//     })
//     res.send("Password Encrypt")
// })

// const hash = "$2b$10$zJXnMhpFFFk9urkmb2j4OeoH3.cSrSg2JK3b.miB0AH2R9XP4NA7W"

// //Password Decryption
// app.get('/compare' , (req, res)=>{
//     bcrypt.compare(pass , hash , (err , result)=>{
//         console.log(result)
//     })
//     res.send("Password Decrypted")
// })





// app.get('/' , (req, res) =>{
//     res.cookie('name' , 'Sam')
//     res.send('welcome')
// })

// app.get('/read' , (req, res) =>{
//    res.send(req.cookies)
// })

app.listen(3000 , ()=> console.log("Server Listen at port  3000"))