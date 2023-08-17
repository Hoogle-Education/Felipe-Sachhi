import { Noticia } from "./components/Noticia"

export function App() {
  const author = {
    name: "John",
    email: "john@gmail.com"
  }

  return (
    <>
      <Noticia title="Title" author="Jhon" content="lorem impsum"/>
      <Noticia title="Apagao terca" author="Maria" content="apagou tudo"/>
    </>
  )
}