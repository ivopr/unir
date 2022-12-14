import Head from 'next/head'
import { useRouter } from 'next/router'
import { FormEvent, useState } from 'react'
import styles from '../styles/Home.module.css'

export default function Home() {
  const [name, setName] = useState("")
  const [email, setEmail] = useState("")
  const [pass, setPass] = useState("")
  const [verifyPass, setVerifyPass] = useState("")
  const [birth, setBirth] = useState("")
  const router = useRouter()

  const userRegister = (e: FormEvent<HTMLFormElement>) => {
    e.preventDefault()
    router.push(`/user?name=${name}&email=${email}&pass=${pass}&birth=${birth}&verifyPass=${verifyPass}`)
  }

  return (
    <div className={styles.container}>
      <Head>
        <title>Criar Usuário</title>
        <meta name="description" content="Generated by create next app" />
        <link rel="icon" href="/favicon.ico" />
      </Head>

      <form onSubmit={userRegister} className={styles.main}>
        <input placeholder="Nome" onChange={(e) => setName(e.target.value)} />
        <input placeholder="Email" onChange={(e) => setEmail(e.target.value)} />
        <input placeholder="Senha" onChange={(e) => setPass(e.target.value)} />
        <input placeholder="Confirmar Senha" onChange={(e) => setVerifyPass(e.target.value)} />
        <input placeholder="Data de Nascimento (dd/mm/aaaa)" onChange={(e) => setBirth(e.target.value)} />
        <button type="submit">Enviar</button>
        <a onClick={() => router.push('/fornecedor')}>Cadastrar Fornecedor</a>
      </form>

    </div>
  )
}
