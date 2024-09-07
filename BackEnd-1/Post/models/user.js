const mongoose = require('mongoose')
mongoose.connect('mongodb://localhost:27017/testpost')

const userSchema = mongoose.Schema({
    name: {
        type: String
    },
    email: String,
    posts: [
        {
            type: mongoose.Schema.Types.ObjectId,
            ref: 'post'
        }
    ]
})


module.exports = mongoose.model('user', userSchema)