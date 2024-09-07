// Import Packages
const express = require('express');
const app = express();
const path = require('path')
const fs = require('fs')

// Parser for form
app.use(express.json());
app.use(express.urlencoded({ extended: true }));
app.use(express.static(path.join(__dirname, 'public')))

// Setting EJS View Engine
app.set('view engine', 'ejs');

// app.get('/', (req, res) => {
//     res.render('index');
// });

// app.get('/', (req, res) => {
//     res.render('index1');
// });

// app.get('/about', (req, res) => {
//     res.render('about');
// });

// //Dynamic Route
// app.get('/user/:username/:age', (req, res) => {
//     const { username , age } = req.params;
//     res.send(`Welcome Bhai ${username} Teri Age ${age}`);
// });

//Notes

app.get('/', (req, res) => {
    fs.readdir('./files', (err, files) => {
        res.render('index1', { files: files })
    })
})


app.post('/create', (req, res) => {
    fs.writeFile(`./files/${req.body.title.split(' ').join('')}.txt`, req.body.details, (err) => {
        res.redirect('/')
    })
})

app.get('/files/:fileName', (req, res) => {
    fs.readFile(`./files/${req.params.fileName}`, 'utf-8', (err, data) => {
        res.render('detail', {
            fileName: req.params.fileName,
            filedata: data
        })
    })
})

app.get('/edittitle/:filename', (req, res) => {
    res.render('edittitle', { filename: req.params.filename })
})

app.post('/edittitle', (req, res) => {
    fs.rename(`./files/${req.body.previous}` , `./files/${req.body.new.split(' ').join('')}.txt` , (err) =>{
        res.redirect('/')
    })
})

app.get('/editdetails/:filename/:filedata' , (req, res)=>{
    res.render('editdetails' ,{
        filename: req.params.filename,
        filedata: req.params.filedata
    })
})

app.post('/editdetails' , (req , res)=>{
    fs.writeFile(`./files/${req.body.title}` , req.body.details , (err) =>{
        res.redirect('/')
    })
})

app.get('/delete/:filename' , (req , res) =>{
    fs.unlink(`./files/${req.params.filename}` , (err) =>{
        res.redirect('/')
    })
})

app.listen(3000, () => { console.log("Server listening at port 3000") });
