const joke = document.querySelector('#btnGenerator')
const displayJoke = document.querySelector('#displayJoke')
const author = document.querySelector('#author')

const getDadJoke = async () => {
    const config = { headers: { Accept: 'application/json' } }
    const res = await axios.get('https://icanhazdadjoke.com/', config);
    return res.data.joke;
}

const showDadJoke = async () => {
    const dadJokeText = await getDadJoke()
    displayJoke.textContent = `"${dadJokeText}"`
    author.textContent = "— Some dad"
}

joke.addEventListener('click', showDadJoke)